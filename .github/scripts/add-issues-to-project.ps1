# Add all issues to GitHub Project Board
# Note: You need to create the project first via web UI

Write-Host "Adding issues to GitHub Project..." -ForegroundColor Green

# Get project ID (you'll need to set this after creating the project)
# To get project ID, go to your project URL and note the number at the end
# Example: https://github.com/users/SametKaras/projects/1 -> PROJECT_NUMBER is 1

Write-Host "`nPlease follow these steps:" -ForegroundColor Yellow
Write-Host "1. Go to: https://github.com/SametKaras/cen429-2025-2026-5-samet-karas-cpp/projects" -ForegroundColor White
Write-Host "2. Create a new project (Board template)" -ForegroundColor White
Write-Host "3. Name it: 'Local Event Planner - Development'" -ForegroundColor White
Write-Host "4. Configure columns: Backlog, Ready, In Progress, In Review, Testing, Done" -ForegroundColor White
Write-Host "5. Enable 'Auto-add to project' in project settings" -ForegroundColor White

Write-Host "`nTo manually add all existing issues to the project:" -ForegroundColor Cyan
Write-Host "1. Click '+ Add item' on your project board" -ForegroundColor White
Write-Host "2. Select 'Add items from repository'" -ForegroundColor White
Write-Host "3. Select all issues (Ctrl+A or Cmd+A)" -ForegroundColor White
Write-Host "4. Click 'Add selected items'" -ForegroundColor White

Write-Host "`nProject setup guide complete!" -ForegroundColor Green

