# Export Project Plan to PDF
# Requires: pandoc (choco install pandoc)

Write-Host "Checking for pandoc..." -ForegroundColor Cyan

$pandocInstalled = Get-Command pandoc -ErrorAction SilentlyContinue

if (-not $pandocInstalled) {
    Write-Host "Pandoc not found!" -ForegroundColor Red
    Write-Host "Install with: choco install pandoc" -ForegroundColor Yellow
    Write-Host "Or download from: https://pandoc.org/installing.html" -ForegroundColor Yellow
    exit 1
}

Write-Host "Converting docs/plan.md to PDF..." -ForegroundColor Green

$inputFile = "..\..\docs\plan.md"
$outputFile = "..\..\docs\LocalEventPlanner_ProjectPlan.pdf"

try {
    pandoc $inputFile -o $outputFile --pdf-engine=xelatex -V geometry:margin=1in
    
    Write-Host ""
    Write-Host "Success! PDF created:" -ForegroundColor Green
    Write-Host "  $outputFile" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "Opening PDF..." -ForegroundColor Yellow
    
    Start-Process $outputFile
}
catch {
    Write-Host "Error: $($_.Exception.Message)" -ForegroundColor Red
    Write-Host ""
    Write-Host "Alternative: Use online converter" -ForegroundColor Yellow
    Write-Host "  https://www.markdowntopdf.com/" -ForegroundColor Blue
}

