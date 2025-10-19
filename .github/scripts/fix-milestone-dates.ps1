# Fix Milestone Dates - Update to 2025
# Simple version using direct gh api calls

Write-Host "Fixing milestone dates to 2025..." -ForegroundColor Green
Write-Host ""

$repo = "SametKaras/cen429-2025-2026-5-samet-karas-cpp"

# Milestone number and new dates
$milestoneUpdates = @(
    @{Number=1; Title="M0"; Date="2025-01-10T23:59:59Z"},
    @{Number=2; Title="M1"; Date="2025-02-28T23:59:59Z"},
    @{Number=3; Title="M2"; Date="2025-03-31T23:59:59Z"},
    @{Number=4; Title="M3"; Date="2025-05-10T23:59:59Z"},
    @{Number=5; Title="M4"; Date="2025-05-31T23:59:59Z"}
)

foreach ($m in $milestoneUpdates) {
    $num = $m.Number
    $title = $m.Title
    $date = $m.Date
    
    Write-Host "Updating milestone $num ($title) to $date" -ForegroundColor Cyan
    
    $json = '{"due_on":"' + $date + '"}'
    
    $apiPath = "repos/$repo/milestones/$num"
    
    echo $json | gh api $apiPath -X PATCH --input - | Out-Null
    
    Write-Host "  Done!" -ForegroundColor Green
}

Write-Host ""
Write-Host "All milestone dates updated to 2025!" -ForegroundColor Green
Write-Host "View at: https://github.com/$repo/milestones" -ForegroundColor Cyan

