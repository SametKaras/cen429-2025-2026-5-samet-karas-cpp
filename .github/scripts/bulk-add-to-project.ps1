# Bulk add all existing issues to Project Board
# Project ID: 4 (from URL: /users/SametKaras/projects/4)

Write-Host "Adding all existing issues to Project Board..." -ForegroundColor Green

$repo = "SametKaras/cen429-2025-2026-5-samet-karas-cpp"
$projectNumber = 4

# Get project ID from the GraphQL API
Write-Host "`nStep 1: Getting Project ID..." -ForegroundColor Yellow

$projectQuery = @"
query {
  user(login: "SametKaras") {
    projectV2(number: $projectNumber) {
      id
    }
  }
}
"@

$projectResult = gh api graphql -f query="$projectQuery" | ConvertFrom-Json
$projectId = $projectResult.data.user.projectV2.id

Write-Host "Project ID: $projectId" -ForegroundColor Cyan

# Get all open issues
Write-Host "`nStep 2: Getting all open issues..." -ForegroundColor Yellow

$issues = gh issue list --repo $repo --state open --limit 1000 --json number,title | ConvertFrom-Json

Write-Host "Found $($issues.Count) open issues" -ForegroundColor Cyan

# Add each issue to the project
Write-Host "`nStep 3: Adding issues to project..." -ForegroundColor Yellow

$successCount = 0
$failCount = 0

foreach ($issue in $issues) {
    $issueNumber = $issue.number
    $issueTitle = $issue.title
    
    Write-Host "  Adding #$issueNumber : $issueTitle" -ForegroundColor Gray
    
    try {
        # Get issue node ID
        $issueData = gh api repos/$repo/issues/$issueNumber --jq '.node_id'
        
        # Add issue to project using GraphQL mutation
        $mutation = @"
mutation {
  addProjectV2ItemById(input: {projectId: \"$projectId\", contentId: \"$issueData\"}) {
    item {
      id
    }
  }
}
"@
        
        gh api graphql -f query="$mutation" | Out-Null
        
        Write-Host "    ✓ Added" -ForegroundColor Green
        $successCount++
        
        Start-Sleep -Milliseconds 100  # Rate limiting
    }
    catch {
        Write-Host "    ✗ Failed: $_" -ForegroundColor Red
        $failCount++
    }
}

Write-Host "`n" + "="*60 -ForegroundColor Cyan
Write-Host "Summary:" -ForegroundColor Green
Write-Host "  Successfully added: $successCount issues" -ForegroundColor Green
Write-Host "  Failed: $failCount issues" -ForegroundColor $(if ($failCount -gt 0) { "Red" } else { "Green" })
Write-Host "="*60 -ForegroundColor Cyan

Write-Host "`nView your project board at:" -ForegroundColor Yellow
Write-Host "https://github.com/users/SametKaras/projects/4" -ForegroundColor Cyan

