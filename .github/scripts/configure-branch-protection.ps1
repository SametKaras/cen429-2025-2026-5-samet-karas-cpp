# Configure Branch Protection for main branch
# This script sets up security rules for the main branch

Write-Host "Setting up branch protection..." -ForegroundColor Green

$owner = "SametKaras"
$repo = "cen429-2025-2026-5-samet-karas-cpp"
$branch = "main"

# JSON configuration for branch protection
$config = @'
{
  "required_status_checks": {
    "strict": true,
    "contexts": []
  },
  "enforce_admins": true,
  "required_pull_request_reviews": {
    "dismiss_stale_reviews": true,
    "require_code_owner_reviews": false,
    "required_approving_review_count": 1
  },
  "restrictions": null,
  "required_linear_history": true,
  "allow_force_pushes": false,
  "allow_deletions": false,
  "required_conversation_resolution": true
}
'@

Write-Host "Applying rules to main branch..." -ForegroundColor Cyan

try {
    $apiUrl = "repos/$owner/$repo/branches/$branch/protection"
    $config | gh api $apiUrl -X PUT --input - | Out-Null
    
    Write-Host "Success! Branch protection enabled." -ForegroundColor Green
    Write-Host "View at: https://github.com/$owner/$repo/settings/branches" -ForegroundColor Blue
}
catch {
    Write-Host "Error: $($_.Exception.Message)" -ForegroundColor Red
    Write-Host "Please configure manually at:" -ForegroundColor Yellow
    Write-Host "https://github.com/$owner/$repo/settings/branches" -ForegroundColor Blue
    exit 1
}

