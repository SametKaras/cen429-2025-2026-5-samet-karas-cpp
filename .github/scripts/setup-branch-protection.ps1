# Setup Branch Protection Rules for main branch
# Implements security best practices for the repository

Write-Host "Configuring branch protection rules for 'main' branch..." -ForegroundColor Green
Write-Host ""

$owner = "SametKaras"
$repoName = "cen429-2025-2026-5-samet-karas-cpp"
$branch = "main"

# Branch protection configuration
$protectionConfig = @'
{
  "required_status_checks": {
    "strict": true,
    "contexts": [
      "Build and Test / build-windows",
      "CodeQL Security Analysis / Analyze C++"
    ]
  },
  "enforce_admins": true,
  "required_pull_request_reviews": {
    "dismissal_restrictions": {},
    "dismiss_stale_reviews": true,
    "require_code_owner_reviews": false,
    "required_approving_review_count": 1,
    "require_last_push_approval": false
  },
  "restrictions": null,
  "required_linear_history": true,
  "allow_force_pushes": false,
  "allow_deletions": false,
  "block_creations": false,
  "required_conversation_resolution": true,
  "lock_branch": false,
  "allow_fork_syncing": true
}
'@

Write-Host "Protection Rules to Apply:" -ForegroundColor Cyan
Write-Host "  - Require pull request reviews (1 approver)" -ForegroundColor White
Write-Host "  - Require status checks to pass before merging" -ForegroundColor White
Write-Host "    * Build and Test (Windows)" -ForegroundColor Gray
Write-Host "    * CodeQL Security Analysis" -ForegroundColor Gray
Write-Host "  - Require linear history (no merge commits)" -ForegroundColor White
Write-Host "  - Dismiss stale reviews on new commits" -ForegroundColor White
Write-Host "  - Require conversation resolution" -ForegroundColor White
Write-Host "  - Enforce for administrators" -ForegroundColor White
Write-Host "  - Block force pushes" -ForegroundColor Yellow
Write-Host "  - Block branch deletion" -ForegroundColor Yellow
Write-Host ""

try {
    Write-Host "Applying protection rules to '$branch' branch..." -ForegroundColor Yellow
    
    $apiPath = "repos/$owner/$repoName/branches/$branch/protection"
    
    $result = $protectionConfig | gh api $apiPath -X PUT --input -
    
    Write-Host ""
    Write-Host ("=" * 70) -ForegroundColor Green
    Write-Host "Branch protection rules applied successfully!" -ForegroundColor Green
    Write-Host ("=" * 70) -ForegroundColor Green
    Write-Host ""
    
    Write-Host "Verification:" -ForegroundColor Cyan
    Write-Host "  View at: https://github.com/$owner/$repoName/settings/branches" -ForegroundColor Blue
    Write-Host ""
    
    Write-Host "What This Means:" -ForegroundColor Yellow
    Write-Host "  ✓ Direct pushes to 'main' are now blocked" -ForegroundColor White
    Write-Host "  ✓ All changes must go through Pull Requests" -ForegroundColor White
    Write-Host "  ✓ PRs must pass CI/CD checks before merging" -ForegroundColor White
    Write-Host "  ✓ PRs need at least 1 approval" -ForegroundColor White
    Write-Host "  ✓ Force pushes are prevented" -ForegroundColor White
    Write-Host ""
    
    Write-Host "Development Workflow:" -ForegroundColor Cyan
    Write-Host "  1. Create feature branch: git checkout -b feature/my-feature" -ForegroundColor Gray
    Write-Host "  2. Make changes and commit" -ForegroundColor Gray
    Write-Host "  3. Push: git push origin feature/my-feature" -ForegroundColor Gray
    Write-Host "  4. Create Pull Request on GitHub" -ForegroundColor Gray
    Write-Host "  5. Wait for CI checks to pass" -ForegroundColor Gray
    Write-Host "  6. Get approval and merge" -ForegroundColor Gray
    Write-Host ""
}
catch {
    Write-Host ""
    Write-Host ("=" * 70) -ForegroundColor Red
    Write-Host "Failed to apply branch protection rules!" -ForegroundColor Red
    Write-Host ("=" * 70) -ForegroundColor Red
    Write-Host ""
    Write-Host "Error: $($_.Exception.Message)" -ForegroundColor Yellow
    Write-Host ""
    
    Write-Host "Manual Setup Instructions:" -ForegroundColor Cyan
    Write-Host "1. Go to: https://github.com/$owner/$repoName/settings/branches" -ForegroundColor White
    Write-Host "2. Click 'Add branch protection rule'" -ForegroundColor White
    Write-Host "3. Branch name pattern: main" -ForegroundColor White
    Write-Host "4. Enable:" -ForegroundColor White
    Write-Host "   - Require a pull request before merging" -ForegroundColor Gray
    Write-Host "   - Require approvals (1)" -ForegroundColor Gray
    Write-Host "   - Dismiss stale pull request approvals" -ForegroundColor Gray
    Write-Host "   - Require status checks to pass" -ForegroundColor Gray
    Write-Host "   - Require branches to be up to date" -ForegroundColor Gray
    Write-Host "   - Require linear history" -ForegroundColor Gray
    Write-Host "   - Require conversation resolution" -ForegroundColor Gray
    Write-Host "   - Do not allow bypassing the above settings" -ForegroundColor Gray
    Write-Host "5. Click 'Create'" -ForegroundColor White
    Write-Host ""
    
    exit 1
}

Write-Host "Branch protection setup complete" -ForegroundColor Green

