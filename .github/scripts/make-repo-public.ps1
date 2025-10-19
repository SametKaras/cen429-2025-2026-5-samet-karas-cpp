# Make Repository Public
# Required for branch protection rules on free GitHub accounts

Write-Host "Making repository public..." -ForegroundColor Yellow
Write-Host ""

$owner = "SametKaras"
$repo = "cen429-2025-2026-5-samet-karas-cpp"

Write-Host "WARNING: This will make your repository visible to everyone!" -ForegroundColor Red
Write-Host "Press any key to continue or Ctrl+C to cancel..."
$null = $Host.UI.RawUI.ReadKey("NoEcho,IncludeKeyDown")

try {
    $config = '{"private":false}'
    $apiUrl = "repos/$owner/$repo"
    
    $config | gh api $apiUrl -X PATCH --input - | Out-Null
    
    Write-Host ""
    Write-Host "Repository is now PUBLIC!" -ForegroundColor Green
    Write-Host "You can now enable branch protection rules." -ForegroundColor Cyan
    Write-Host ""
    Write-Host "Run: .\configure-branch-protection.ps1" -ForegroundColor Yellow
}
catch {
    Write-Host "Error: $($_.Exception.Message)" -ForegroundColor Red
    exit 1
}

