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

# M2 Issues
$m2Issues = @(
    @{
        title="Issue 2.1 - Memory Data Security"
        body=@"
## Description
Implement secure memory handling, encryption of data in use, and secure deletion.

## Output
- [ ] src/security/memguard.h/cpp
- [ ] Secure memory allocation
- [ ] Memory encryption functions
- [ ] Secure memory wiping
- [ ] Memory protection tests

## Acceptance Criteria
- Sensitive data encrypted in memory
- Memory securely cleared after use
- No memory leaks detected
"@
        labels="type:security,area:mem"
        milestone="M2 - Midterm and First Security Layer"
    },
    @{
        title="Issue 2.2 - Payload Encryption and MAC"
        body=@"
## Description
Implement AES encryption and HMAC-SHA256 for payload security.

## Output
- [ ] src/security/transport.h/cpp
- [ ] AES-256 encryption/decryption
- [ ] HMAC-SHA256 implementation
- [ ] Key derivation functions
- [ ] Transport security tests

## Acceptance Criteria
- Payload encrypted with AES-256
- HMAC validation working
- Tests 100% coverage
"@
        labels="type:security,area:crypto,priority:P1"
        milestone="M2 - Midterm and First Security Layer"
    },
    @{
        title="Issue 2.3 - Session Key Management"
        body=@"
## Description
Implement session key generation, encryption, and rotation.

## Output
- [ ] SessionKeyManager class
- [ ] Key generation (secure random)
- [ ] Key encryption/decryption
- [ ] Key rotation policy
- [ ] Secure key storage

## Acceptance Criteria
- Session keys cryptographically secure
- Key rotation automated
- Keys never stored in plaintext
"@
        labels="type:security,area:crypto,priority:P1"
        milestone="M2 - Midterm and First Security Layer"
    },
    @{
        title="Issue 2.4 - Midterm Report Preparation"
        body=@"
## Description
Prepare midterm report covering M0-M2 progress.

## Output
- [ ] docs/reports/midterm.md
- [ ] PDF version
- [ ] Screenshots of working features
- [ ] Test results included

## Acceptance Criteria
- All M0-M2 work documented
- Authentication system demonstrated
- Security features explained
"@
        labels="type:docs"
        milestone="M2 - Midterm and First Security Layer"
    }
)

Write-Host "`nCreating M2 issues... ($($m2Issues.Count) count)" -ForegroundColor Yellow
foreach ($issue in $m2Issues) {
    Write-Host "  -> $($issue.title)" -ForegroundColor Gray
    $labels = $issue.labels -split ','
    $body = @{
        title = $issue.title
        body = $issue.body
        labels = $labels
        milestone = 3  # M2 is third milestone (ID=3)
    } | ConvertTo-Json -Compress
    $body | gh api repos/:owner/:repo/issues -X POST --input - 2>&1 | Out-Null
}

# M3 Issues
$m3Issues = @(
    @{
        title="Issue 3.1 - Storage Security"
        body=@"
## Description
Implement Whitebox AES/DES for database file encryption.

## Output
- [ ] src/security/storage.h/cpp
- [ ] Whitebox AES implementation
- [ ] Whitebox DES implementation
- [ ] Multi-layer encryption
- [ ] SQLCipher integration

## Acceptance Criteria
- Database files encrypted
- Multiple encryption layers active
- Decryption only possible in app context
"@
        labels="type:security,area:storage"
        milestone="M3 - Advanced Security RASP and Hardening"
    },
    @{
        title="Issue 3.2 - SoftHSM Integration"
        body=@"
## Description
Integrate SoftHSM2 for cryptographic key storage.

## Output
- [ ] src/security/hsm/HSMKeyManager.h/cpp
- [ ] SoftHSM2 configuration
- [ ] PKCS#11 interface implementation
- [ ] Master key protection
- [ ] HSM tests
- [ ] docs/hsm-setup.md

## Acceptance Criteria
- SoftHSM2 configured and working
- Crypto keys stored in HSM
- Master key never in plaintext
"@
        labels="type:security,area:hsm,priority:P1"
        milestone="M3 - Advanced Security RASP and Hardening"
    },
    @{
        title="Issue 3.3 - Static and Dynamic Asset Protection"
        body=@"
## Description
Implement protection for keys, hashes, source code, and runtime assets.

## Output
- [ ] Asset encryption mechanisms
- [ ] Access control lists
- [ ] Resource file protection
- [ ] Dynamic key obfuscation
- [ ] docs/asset-inventory/inventory.md completed

## Acceptance Criteria
- All sensitive assets identified
- Protection mechanisms implemented
- Asset inventory complete
"@
        labels="type:security,area:assets"
        milestone="M3 - Advanced Security RASP and Hardening"
    },
    @{
        title="Issue 3.4 - Device Fingerprinting"
        body=@"
## Description
Implement hardware-based device identification and binding.

## Output
- [ ] src/security/DeviceFingerprint.h/cpp
- [ ] CPU ID collection
- [ ] MAC address collection
- [ ] Disk serial collection
- [ ] Fingerprint generation
- [ ] Device binding for sessions

## Acceptance Criteria
- Unique device fingerprint generated
- Sessions bound to devices
- Device change detected
"@
        labels="type:security,area:device"
        milestone="M3 - Advanced Security RASP and Hardening"
    },
    @{
        title="Issue 3.5 - Code Hardening"
        body=@"
## Description
Implement code obfuscation techniques: opaque loops, string hiding, control flow obfuscation.

## Output
- [ ] src/security/obf.h/cpp
- [ ] Opaque boolean variables
- [ ] String encryption
- [ ] Function name obfuscation
- [ ] Control flow flattening
- [ ] Fake branches

## Acceptance Criteria
- Code difficult to reverse engineer
- String literals encrypted
- Control flow obscured
"@
        labels="type:security,area:obf"
        milestone="M3 - Advanced Security RASP and Hardening"
    },
    @{
        title="Issue 3.6 - RASP Module"
        body=@"
## Description
Implement Runtime Application Self-Protection: anti-debug, checksum, tamper detection.

## Output
- [ ] src/security/rasp/RuntimeProtection.h/cpp
- [ ] Anti-debugging mechanisms
- [ ] Checksum verification
- [ ] Hook detection
- [ ] Emulator detection
- [ ] Root/jailbreak detection
- [ ] Tamper response mechanisms

## Acceptance Criteria
- Debugger attachment prevented
- Code integrity verified at runtime
- Tampering triggers response
"@
        labels="type:security,area:rasp,priority:P1"
        milestone="M3 - Advanced Security RASP and Hardening"
    },
    @{
        title="Issue 3.7 - SSL/TLS and Certificate Pinning"
        body=@"
## Description
Implement secure TLS connections with certificate pinning.

## Output
- [ ] src/security/tls.h/cpp
- [ ] TLS 1.3 support
- [ ] Certificate pinning
- [ ] Mutual authentication
- [ ] Certificate validation tests

## Acceptance Criteria
- TLS connections encrypted
- Certificate pinning working
- MITM attacks prevented
"@
        labels="type:security,area:tls"
        milestone="M3 - Advanced Security RASP and Hardening"
    },
    @{
        title="Issue 3.8 - Memory Protection (SafeStack)"
        body=@"
## Description
Implement Clang SafeStack for stack overflow protection.

## Output
- [ ] SafeStack CMake configuration
- [ ] Stack overflow protection tests
- [ ] Buffer overflow mitigation
- [ ] Secure memory cleanup functions

## Acceptance Criteria
- SafeStack enabled in build
- Stack overflow attempts blocked
- Memory protection tests pass
"@
        labels="type:security,area:mem"
        milestone="M3 - Advanced Security RASP and Hardening"
    },
    @{
        title="Issue 3.9 - Asset Inventory - Phase 2"
        body=@"
## Description
Document all crypto keys, certificates, and HSM tokens from M3.

## Output
- [ ] docs/asset-inventory/phase2.md
- [ ] Crypto keys inventory
- [ ] Certificates inventory
- [ ] HSM tokens inventory
- [ ] Protection schemas verified

## Acceptance Criteria
- All M3 assets documented
- Metadata complete
- Protection mechanisms verified
"@
        labels="type:docs,area:assets"
        milestone="M3 - Advanced Security RASP and Hardening"
    }
)

Write-Host "`nCreating M3 issues... ($($m3Issues.Count) count)" -ForegroundColor Yellow
foreach ($issue in $m3Issues) {
    Write-Host "  -> $($issue.title)" -ForegroundColor Gray
    $labels = $issue.labels -split ','
    $body = @{
        title = $issue.title
        body = $issue.body
        labels = $labels
        milestone = 4  # M3 is fourth milestone (ID=4)
    } | ConvertTo-Json -Compress
    $body | gh api repos/:owner/:repo/issues -X POST --input - 2>&1 | Out-Null
}

# M4 Issues
$m4Issues = @(
    @{
        title="Issue 4.1 - Test Coverage and Fuzzing"
        body=@"
## Description
Achieve 80%+ test coverage and implement fuzzing tests.

## Output
- [ ] Unit tests for all modules
- [ ] Integration tests
- [ ] Fuzz testing setup
- [ ] Coverage report >=80%
- [ ] CI tests passing

## Acceptance Criteria
- Code coverage >= 80%
- All critical paths tested
- Fuzz tests catching edge cases
"@
        labels="type:test,area:test"
        milestone="M4 - Tests Pentest and Final Report"
    },
    @{
        title="Issue 4.2 - Penetration Test Plan"
        body=@"
## Description
Create and execute penetration testing plan.

## Output
- [ ] docs/pentest-plan/plan.md
- [ ] STRIDE threat model
- [ ] Test scenarios defined
- [ ] Tools identified (Burp, OWASP ZAP)
- [ ] Pentest execution results
- [ ] Vulnerability report

## Acceptance Criteria
- Complete pentest plan documented
- All scenarios executed
- Vulnerabilities identified and fixed
"@
        labels="type:security,area:pentest"
        milestone="M4 - Tests Pentest and Final Report"
    },
    @{
        title="Issue 4.3 - OWASP Top 10 Compliance Verification"
        body=@"
## Description
Verify compliance with OWASP Top 10 2021 standards.

## Output
- [ ] docs/owasp-compliance.md
- [ ] Test scenarios for each OWASP item
- [ ] Compliance test results
- [ ] Gap analysis
- [ ] Remediation actions (if needed)

## Acceptance Criteria
- All OWASP Top 10 items tested
- Compliance documented
- Critical issues resolved
"@
        labels="type:security,area:owasp,priority:P1"
        milestone="M4 - Tests Pentest and Final Report"
    },
    @{
        title="Issue 4.4 - Security Certification Documentation"
        body=@"
## Description
Prepare security certification documentation (ETSI/EMV/GSMA style).

## Output
- [ ] docs/security-certification/
- [ ] Security evaluation report
- [ ] Threat modeling (STRIDE)
- [ ] Security architecture document
- [ ] Compliance matrices

## Acceptance Criteria
- Complete certification package
- All security controls documented
- Ready for external audit
"@
        labels="type:docs,area:security"
        milestone="M4 - Tests Pentest and Final Report"
    },
    @{
        title="Issue 4.5 - Asset Inventory - Final"
        body=@"
## Description
Consolidate all asset inventory phases into final comprehensive document.

## Output
- [ ] docs/asset-inventory/final.md
- [ ] All phases merged
- [ ] Missing assets added
- [ ] Protection schemas verified for all assets
- [ ] Asset lifecycle documented

## Acceptance Criteria
- Complete asset inventory
- Every asset has metadata
- Protection mechanisms verified
"@
        labels="type:docs,area:assets"
        milestone="M4 - Tests Pentest and Final Report"
    },
    @{
        title="Issue 4.6 - Final Report and Presentation"
        body=@"
## Description
Prepare final technical report and presentation.

## Output
- [ ] docs/reports/final-report.md
- [ ] PDF version
- [ ] PowerPoint/PDF presentation
- [ ] Demo video (optional)
- [ ] All deliverables packaged

## Acceptance Criteria
- Complete final report
- SoftHSM integration documented
- Authentication system documented
- OWASP compliance results included
- Security certification status included
- Presentation ready for defense
"@
        labels="type:docs,priority:P1"
        milestone="M4 - Tests Pentest and Final Report"
    }
)

Write-Host "`nCreating M4 issues... ($($m4Issues.Count) count)" -ForegroundColor Yellow
foreach ($issue in $m4Issues) {
    Write-Host "  -> $($issue.title)" -ForegroundColor Gray
    $labels = $issue.labels -split ','
    $body = @{
        title = $issue.title
        body = $issue.body
        labels = $labels
        milestone = 5  # M4 is fifth milestone (ID=5)
    } | ConvertTo-Json -Compress
    $body | gh api repos/:owner/:repo/issues -X POST --input - 2>&1 | Out-Null
}

Write-Host "`nAll issues created!" -ForegroundColor Green
Write-Host "`nSummary:" -ForegroundColor Cyan
Write-Host "  M1: $($m1Issues.Count) issues" -ForegroundColor White
Write-Host "  M2: $($m2Issues.Count) issues" -ForegroundColor White
Write-Host "  M3: $($m3Issues.Count) issues" -ForegroundColor White
Write-Host "  M4: $($m4Issues.Count) issues" -ForegroundColor White
Write-Host "  TOTAL: $(($m1Issues.Count + $m2Issues.Count + $m3Issues.Count + $m4Issues.Count)) new issues" -ForegroundColor Green

$repoUrl = gh repo view --json url -q .url
Write-Host "`nIssues: $repoUrl/issues" -ForegroundColor Cyan
Write-Host "Milestones: $repoUrl/milestones" -ForegroundColor Cyan
