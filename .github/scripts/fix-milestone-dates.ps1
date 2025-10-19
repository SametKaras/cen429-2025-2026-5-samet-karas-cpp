# Fix Milestone Dates - Update to Academic Calendar
# Based on:
# - Project Start: 04.10.2025
# - Midterm Report: 07.11.2025
# - Final Report: 02.02.2026

Write-Host "Updating milestone dates to match academic calendar..." -ForegroundColor Green
Write-Host ""

$repo = "SametKaras/cen429-2025-2026-5-samet-karas-cpp"

# Milestone number and new dates based on academic calendar
$milestoneUpdates = @(
    @{Number=1; Title="M0 - Project Plan and Approval"; Date="2025-10-18T23:59:59Z"; Note="2 weeks for planning"},
    @{Number=2; Title="M1 - Core Features and Basic Security"; Date="2025-10-31T23:59:59Z"; Note="Before midterm"},
    @{Number=3; Title="M2 - Midterm and First Security Layer"; Date="2025-11-07T23:59:59Z"; Note="MIDTERM DATE"},
    @{Number=4; Title="M3 - Advanced Security RASP and Hardening"; Date="2026-01-15T23:59:59Z"; Note="Before final"},
    @{Number=5; Title="M4 - Tests Pentest and Final Report"; Date="2026-02-02T23:59:59Z"; Note="FINAL DATE"}
)

Write-Host "Academic Calendar:" -ForegroundColor Cyan
Write-Host "  Project Start:   04.10.2025" -ForegroundColor Gray
Write-Host "  Midterm Report:  07.11.2025" -ForegroundColor Yellow
Write-Host "  Final Report:    02.02.2026" -ForegroundColor Yellow
Write-Host ""

foreach ($m in $milestoneUpdates) {
    $num = $m.Number
    $title = $m.Title
    $date = $m.Date
    $note = $m.Note
    
    Write-Host "Updating Milestone $num" -ForegroundColor Cyan
    Write-Host "  Title: $title" -ForegroundColor Gray
    Write-Host "  Date:  $date" -ForegroundColor Gray
    Write-Host "  Note:  $note" -ForegroundColor DarkGray
    
    $json = '{"due_on":"' + $date + '"}'
    
    $apiPath = "repos/$repo/milestones/$num"
    
    echo $json | gh api $apiPath -X PATCH --input - | Out-Null
    
    Write-Host "  Done!" -ForegroundColor Green
    Write-Host ""
}

Write-Host ("=" * 70) -ForegroundColor Cyan
Write-Host "All milestone dates updated to match academic calendar!" -ForegroundColor Green
Write-Host ("=" * 70) -ForegroundColor Cyan
Write-Host ""

Write-Host "Timeline Summary:" -ForegroundColor Yellow
Write-Host "  M0: 18.10.2025 - Project Plan and Approval (2 weeks)" -ForegroundColor White
Write-Host "  M1: 31.10.2025 - Core Features (before midterm)" -ForegroundColor White
Write-Host "  M2: 07.11.2025 - Midterm Report & First Security Layer" -ForegroundColor Yellow
Write-Host "  M3: 15.01.2026 - Advanced Security & RASP" -ForegroundColor White
Write-Host "  M4: 02.02.2026 - Final Report, Pentest & Testing" -ForegroundColor Yellow
Write-Host ""

Write-Host "View milestones at:" -ForegroundColor Cyan
Write-Host "https://github.com/$repo/milestones" -ForegroundColor Blue
