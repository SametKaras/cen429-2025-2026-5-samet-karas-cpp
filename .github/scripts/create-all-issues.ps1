# Local Event Planner - Create All Issues
# Creates all issues for M1, M2, M3, M4 milestones

Write-Host "Creating M1, M2, M3, M4 Issues..." -ForegroundColor Green

# M1 Issues
$m1Issues = @(
    @{
        title="Issue 1.1 - Create Domain Models"
        body=@"
## Description
Define Event, Attendee, Schedule, Feedback classes and data structures.

## Output
- [ ] src/core/models/Event.h and Event.cpp
- [ ] src/core/models/Attendee.h and Attendee.cpp
- [ ] src/core/models/Schedule.h and Schedule.cpp
- [ ] src/core/models/Feedback.h and Feedback.cpp
- [ ] Model tests written

## Acceptance Criteria
- All domain models support CRUD operations
- Data validation implemented
- Tests 90%+ coverage
"@
        labels="type:feature,area:core,priority:P1"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.2 - User Authentication and Authorization System"
        body=@"
## Description
- User registration/login system
- Password hashing (PBKDF2-SHA256)
- Role-based access control
- Session token generation and validation

## Output
- [ ] src/core/auth/AuthManager.h/cpp
- [ ] src/core/auth/User.h/cpp
- [ ] src/core/auth/Role.h/cpp
- [ ] Password hashing implementation
- [ ] Authentication tests

## Acceptance Criteria
- Register/Login working
- Password securely hashed
- Session tokens generated
- Role-based authorization active
"@
        labels="type:feature,area:auth,priority:P1"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.3 - Session Management"
        body=@"
## Description
- Session token creation/validation
- Session expiration control
- Multi-device session support
- Secure session storage

## Output
- [ ] src/core/auth/SessionManager.h/cpp
- [ ] Session encryption
- [ ] Session database table
- [ ] Session tests

## Acceptance Criteria
- Session timeout working
- Token refresh mechanism
- Concurrent session control
"@
        labels="type:feature,area:auth,priority:P1"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.4 - Audit Logging System"
        body=@"
## Description
- Log all critical operations
- User actions, security events, data access
- Tamper-proof log storage
- Log encryption

## Output
- [ ] src/core/audit/AuditLogger.h/cpp
- [ ] Audit log database table
- [ ] Log format (JSON)
- [ ] Log viewer utility

## Acceptance Criteria
- All CRUD operations logged
- Security events logged
- Logs encrypted and immutable
"@
        labels="type:feature,area:security,priority:P1"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.5 - CRUD Functions Implementation (DLL)"
        body=@"
## Description
Implement Event, Attendee, Schedule, Feedback CRUD operations in DLL.

## Output
- [ ] core-secure.dll compiles successfully
- [ ] EventManager CRUD
- [ ] AttendeeManager CRUD (+ check-in/out)
- [ ] ScheduleManager CRUD
- [ ] FeedbackManager CRUD
- [ ] Export interface

## Acceptance Criteria
- DLL successfully compiles and tests
- All CRUD operations working
- Permission control integrated
"@
        labels="type:feature,area:core"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.6 - SQLite Access Layer"
        body=@"
## Description
sqlite3 integration, table migrations and CRUD operations as DAO pattern.

## Output
- [ ] src/persistence/Database.h/cpp
- [ ] Migration scripts
- [ ] DAO pattern implementation
- [ ] Connection pooling
- [ ] Database encryption (SQLCipher)

## Acceptance Criteria
- All tables created
- Migration system working
- CRUD operations reflect to database
"@
        labels="type:feature,area:sqlite"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.7 - Console User Interface (CLI)"
        body=@"
## Description
CLI allowing users to add, list, delete events via terminal.

## Output
- [ ] src/app/main.cpp
- [ ] Menu system
- [ ] Login/Register screens
- [ ] Guest mode
- [ ] Input validation

## Acceptance Criteria
- All features accessible from CLI
- Guest and authenticated mode separation
- User-friendly interface
"@
        labels="type:feature,area:app"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.8 - Unit Test Infrastructure"
        body=@"
## Description
Setup test system with GoogleTest. Write CRUD tests.

## Output
- [ ] GoogleTest integration
- [ ] CTest configuration
- [ ] Model tests
- [ ] CRUD tests
- [ ] Coverage report

## Acceptance Criteria
- ctest runs successfully
- Minimum 70% code coverage
- Tests run automatically in CI
"@
        labels="type:test,area:test,priority:P1"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.9 - Asset Inventory - Phase 1"
        body=@"
## Description
Document all assets created in M1

## Output
- [ ] docs/asset-inventory/phase1.md
- [ ] User credentials inventory
- [ ] Session tokens inventory
- [ ] Database tables inventory

## Acceptance Criteria
- Metadata complete for each asset
- Protection schemas defined
"@
        labels="type:docs,area:assets"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.10 - Guest Mode Implementation"
        body=@"
## Description
Allow guest users to view system without registration

## Output
- [ ] GuestAccessController class
- [ ] Permission enum (GUEST, USER, ADMIN)
- [ ] Guest mode tests
- [ ] Guest Mode menu in CLI

## Acceptance Criteria
- Guest users can only read
- Public events viewable
- Guest session tracking working
"@
        labels="type:feature,area:auth,priority:P2"
        milestone="M1 - Core Features and Basic Security"
    },
    @{
        title="Issue 1.11 - Permission and Authorization System"
        body=@"
## Description
Role-based access control (RBAC) implementation

## Output
- [ ] PermissionManager class
- [ ] checkPermission(user, resource, action)
- [ ] Authorization middleware
- [ ] Resource ownership validation

## Acceptance Criteria
- Permission matrix working
- Unauthorized access blocked
- Tests 100% coverage
"@
        labels="type:security,area:auth,priority:P1"
        milestone="M1 - Core Features and Basic Security"
    }
)

Write-Host "`nCreating M1 issues... ($($m1Issues.Count) count)" -ForegroundColor Yellow
foreach ($issue in $m1Issues) {
    Write-Host "  -> $($issue.title)" -ForegroundColor Gray
    $labels = $issue.labels -split ','
    $body = @{
        title = $issue.title
        body = $issue.body
        labels = $labels
        milestone = 2  # M1 is second milestone (ID=2)
    } | ConvertTo-Json -Compress
    $body | gh api repos/:owner/:repo/issues -X POST --input - 2>&1 | Out-Null
}

Write-Host "`nAll issues created!" -ForegroundColor Green
Write-Host "`nSummary:" -ForegroundColor Cyan
Write-Host "  M1: $($m1Issues.Count) issues" -ForegroundColor White

$repoUrl = gh repo view --json url -q .url
Write-Host "`nIssues: $repoUrl/issues" -ForegroundColor Cyan
Write-Host "`nNote: M2, M3, M4 issues can be added similarly." -ForegroundColor Yellow
Write-Host "Run this script again after M1 completion." -ForegroundColor Yellow
