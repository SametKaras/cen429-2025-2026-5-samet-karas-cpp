# Update Milestone Due Dates to 2025

Write-Host "Updating milestone due dates to 2025..." -ForegroundColor Green

$owner = "SametKaras"
$repoName = "cen429-2025-2026-5-samet-karas-cpp"
$repoPath = "$owner/$repoName"

# Get all milestones
Write-Host "`nFetching current milestones..." -ForegroundColor Yellow

$milestonesJson = gh api "repos/$repoPath/milestones" --jq '.'
$milestones = $milestonesJson | ConvertFrom-Json

Write-Host "Current milestones:" -ForegroundColor Cyan
foreach ($m in $milestones) {
    Write-Host "  #$($m.number): $($m.title) - Due: $($m.due_on)" -ForegroundColor Gray
}

# Define new due dates for 2025
$updates = @(
    @{ Title = "M0 - Project Plan & Approval"; Date = "2025-01-10T23:59:59Z" },
    @{ Title = "M1 - Core App & Basic Security"; Date = "2025-02-28T23:59:59Z" },
    @{ Title = "M2 - Midterm & Initial Security"; Date = "2025-03-31T23:59:59Z" },
    @{ Title = "M3 - Advanced Security & RASP"; Date = "2025-05-10T23:59:59Z" },
    @{ Title = "M4 - Testing, Pentest & Final"; Date = "2025-05-31T23:59:59Z" }
)

Write-Host "`nUpdating milestone dates..." -ForegroundColor Yellow

$successCount = 0
$failCount = 0

foreach ($update in $updates) {
    $milestone = $milestones | Where-Object { $_.title -eq $update.Title }
    
    if ($milestone) {
        $number = $milestone.number
        $title = $update.Title
        $newDate = $update.Date
        
        Write-Host "  Updating #$number : $title" -ForegroundColor Gray
        Write-Host "    Old date: $($milestone.due_on)" -ForegroundColor DarkGray
        Write-Host "    New date: $newDate" -ForegroundColor Cyan
        
        try {
            $jsonBody = @"
{
  "due_on": "$newDate"
}
"@
            
            $result = $jsonBody | gh api "repos/$repoPath/milestones/$number" -X PATCH --input -
            
            Write-Host "    ✓ Updated successfully" -ForegroundColor Green
            $successCount++
        }
        catch {
            Write-Host "    ✗ Failed: $($_.Exception.Message)" -ForegroundColor Red
            $failCount++
        }
    }
    else {
        Write-Host "  ⚠ Milestone not found: $($update.Title)" -ForegroundColor Yellow
    }
}

Write-Host ""
Write-Host ("=" * 60) -ForegroundColor Cyan
Write-Host "Summary:" -ForegroundColor Green
Write-Host "  Successfully updated: $successCount milestones" -ForegroundColor Green
if ($failCount -gt 0) {
    Write-Host "  Failed: $failCount milestones" -ForegroundColor Red
}
Write-Host ("=" * 60) -ForegroundColor Cyan

Write-Host "`nView milestones at:" -ForegroundColor Yellow
$url = "https://github.com/{0}/milestones" -f $repoPath
Write-Host $url -ForegroundColor Cyan
