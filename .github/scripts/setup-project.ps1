# Local Event Planner - GitHub Project Setup Script
# This script automatically creates all milestones, labels and issues

# Helper function for colored output
function Write-ColorOutput($ForegroundColor) {
    $fc = $host.UI.RawUI.ForegroundColor
    $host.UI.RawUI.ForegroundColor = $ForegroundColor
    if ($args) {
        Write-Output $args
    }
    $host.UI.RawUI.ForegroundColor = $fc
}

Write-ColorOutput Green "Local Event Planner - GitHub Project Setup"
Write-ColorOutput Green "=========================================="

# Check if GitHub CLI is installed
if (-not (Get-Command gh -ErrorAction SilentlyContinue)) {
    Write-ColorOutput Red "GitHub CLI (gh) is not installed!"
    Write-ColorOutput Yellow "Please run: winget install --id GitHub.cli"
    exit 1
}

# Check if authenticated
$authStatus = gh auth status 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-ColorOutput Red "Not authenticated to GitHub!"
    Write-ColorOutput Yellow "Please run: gh auth login"
    exit 1
}

Write-ColorOutput Green "GitHub CLI ready"
Write-ColorOutput Cyan "`n1. CREATING LABELS..."

# Create labels
$labels = @(
    @{name="type:feature"; color="0e8a16"; description="New feature"},
    @{name="type:security"; color="d93f0b"; description="Security related"},
    @{name="type:docs"; color="0075ca"; description="Documentation"},
    @{name="type:test"; color="fbca04"; description="Testing"},
    @{name="type:bug"; color="d73a4a"; description="Bug"},
    @{name="area:auth"; color="d4c5f9"; description="Authentication/Authorization"},
    @{name="area:core"; color="c5def5"; description="Core functionality"},
    @{name="area:crypto"; color="f9d0c4"; description="Cryptography"},
    @{name="area:sqlite"; color="bfdadc"; description="Database"},
    @{name="area:app"; color="fef2c0"; description="Application"},
    @{name="area:test"; color="e4e669"; description="Testing infrastructure"},
    @{name="area:mem"; color="c2e0c6"; description="Memory management"},
    @{name="area:hsm"; color="ff6b6b"; description="Hardware Security Module"},
    @{name="area:rasp"; color="ee5a6f"; description="Runtime Application Self-Protection"},
    @{name="area:assets"; color="a0d9b4"; description="Asset management"},
    @{name="area:ci"; color="5a6c7d"; description="CI/CD"},
    @{name="area:management"; color="95a5a6"; description="Project management"},
    @{name="priority:P0"; color="b60205"; description="Blocker - Critical"},
    @{name="priority:P1"; color="d93f0b"; description="High priority"},
    @{name="priority:P2"; color="fbca04"; description="Medium priority"},
    @{name="priority:P3"; color="0e8a16"; description="Low priority"}
)

foreach ($label in $labels) {
    Write-Host "  Creating label: $($label.name)" -ForegroundColor Gray
    gh label create $label.name --color $label.color --description $label.description --force 2>&1 | Out-Null
}

Write-ColorOutput Green "Labels created ($($labels.Count) count)"

Write-ColorOutput Cyan "`n2. CREATING MILESTONES..."

# Create milestones
$milestones = @(
    @{
        title="M0 - Project Plan and Approval"
        due="2024-10-10"
        description="Goal: Setup GitHub repo, project plan and security policies.`nCriteria: CI, CodeQL and Project board must be working."
    },
    @{
        title="M1 - Core Features and Basic Security"
        due="2024-11-05"
        description="Goal: Basic app skeleton, CRUD operations, SQLite connection and test infrastructure.`nCriteria: Event, Attendee, Schedule and Feedback modules working via DLL."
    },
    @{
        title="M2 - Midterm and First Security Layer"
        due="2024-11-07"
        description="Goal: Data security in use, encryption and Midterm report submission.`nCriteria: Memory protection and data encryption functions working."
    },
    @{
        title="M3 - Advanced Security RASP and Hardening"
        due="2024-12-31"
        description="Goal: Data protection, certificate validation, RASP and code hardening.`nCriteria: All security layers active; app has anti-debug and checksum validation."
    },
    @{
        title="M4 - Tests Pentest and Final Report"
        due="2025-02-02"
        description="Goal: Testing entire system, applying pentest plan and final submission.`nCriteria: 80%+ test coverage, pentest plan complete, final report and presentation ready."
    }
)

foreach ($ms in $milestones) {
    Write-Host "  Creating milestone: $($ms.title)" -ForegroundColor Gray
    $body = @{
        title = $ms.title
        due_on = $ms.due + "T23:59:59Z"
        description = $ms.description
    } | ConvertTo-Json -Compress
    $body | gh api repos/:owner/:repo/milestones -X POST --input - 2>&1 | Out-Null
}

Write-ColorOutput Green "Milestones created ($($milestones.Count) count)"

Write-ColorOutput Cyan "`n3. CREATING ISSUES..."

# M0 Issues
$m0Issues = @(
    @{
        title="Issue 0.1 - Add Project Plan"
        body=@"
## Description
Add prepared project plan (docs/plan.md) to the repo and commit it.

## Output
- [ ] docs/plan.md file created
- [ ] Signed commit in log: feat(docs): add project plan
- [ ] Milestone and issue list added

## Acceptance Criteria
- Project plan in markdown format
- All milestones detailed
- Issues clearly defined
"@
        labels="type:docs,priority:P1"
        milestone="M0 - Project Plan and Approval"
    },
    @{
        title="Issue 0.2 - Setup GitHub Project Board"
        body=@"
## Description
Create project view with columns: Backlog, Ready, In Progress, In Review, Testing, Done

## Output
- [ ] GitHub Projects board created
- [ ] Columns defined
- [ ] Board link and screenshot added to project plan

## Acceptance Criteria
- All issues visible on board
- Automatic card addition active
- Workflow automation configured
"@
        labels="type:docs,area:management"
        milestone="M0 - Project Plan and Approval"
    },
    @{
        title="Issue 0.3 - Setup CI and CodeQL"
        body=@"
## Description
- .github/workflows/build.yml (CMake build + CTest)
- .github/workflows/codeql.yml will be configured, CodeQL security scanning active

## Output
- [ ] build.yml workflow added
- [ ] codeql.yml workflow added
- [ ] CI workflows passing green

## Acceptance Criteria
- CMake build successful
- Test suite running
- CodeQL security scanning active
"@
        labels="type:security,area:ci"
        milestone="M0 - Project Plan and Approval"
    },
    @{
        title="Issue 0.4 - Branch Protection and Signed Commits"
        body=@"
## Description
main branch will be protected, squash merge and signed commits will be required.

## Output
- [ ] Branch protection rules active
- [ ] Require signed commits enabled
- [ ] Require pull request reviews
- [ ] Require status checks

## Acceptance Criteria
- Direct push to main blocked
- PR approval required
- GPG signed commits required
"@
        labels="type:security,priority:P2"
        milestone="M0 - Project Plan and Approval"
    },
    @{
        title="Issue 0.5 - Label Set and Issue Templates"
        body=@"
## Description
Label set and issue/pr templates will be added to .github/ISSUE_TEMPLATE/ directory.

## Output
- [ ] Issue templates created
- [ ] PR template added
- [ ] All labels defined

## Acceptance Criteria
- Feature request template
- Bug report template
- Security issue template
- PR template with checklist
"@
        labels="type:docs,area:management"
        milestone="M0 - Project Plan and Approval"
    },
    @{
        title="Issue 0.6 - Approval Request"
        body=@"
## Description
Project plan, GitHub project and workflow screenshots will be sent to advisor for approval.

## Output
- [ ] Project plan prepared as PDF
- [ ] Screenshots added
- [ ] Approval request email sent
- [ ] Project plan approved response received

## Acceptance Criteria
- Advisor approval obtained
- Feedbacks applied
"@
        labels="type:docs,priority:P1"
        milestone="M0 - Project Plan and Approval"
    }
)

Write-ColorOutput Yellow "`nCreating M0 issues..."
foreach ($issue in $m0Issues) {
    Write-Host "  Creating: $($issue.title)" -ForegroundColor Gray
    $labels = $issue.labels -split ','
    $body = @{
        title = $issue.title
        body = $issue.body
        labels = $labels
        milestone = 1  # M0 is first milestone (ID=1)
    } | ConvertTo-Json -Compress
    $body | gh api repos/:owner/:repo/issues -X POST --input - 2>&1 | Out-Null
}

Write-ColorOutput Green "Issues created"
Write-ColorOutput Cyan "`n=========================================="
Write-ColorOutput Green "SETUP COMPLETE!"
Write-ColorOutput Cyan "`nCreated resources:"
Write-ColorOutput White "  - $($labels.Count) labels"
Write-ColorOutput White "  - $($milestones.Count) milestones"
Write-ColorOutput White "  - $($m0Issues.Count) issues (M0)"
Write-ColorOutput Cyan "`nNext steps:"
Write-ColorOutput White "  1. Check GitHub Issues tab"
Write-ColorOutput White "  2. Setup Project board (Issue 0.2)"
Write-ColorOutput White "  3. To create M1, M2, M3, M4 issues:"
Write-ColorOutput Yellow "     .\.github\scripts\create-all-issues.ps1"

Write-ColorOutput Cyan "`nLinks:"
$repoUrl = gh repo view --json url -q .url
Write-ColorOutput White "  Issues: $repoUrl/issues"
Write-ColorOutput White "  Milestones: $repoUrl/milestones"
Write-ColorOutput White "  Projects: $repoUrl/projects"
