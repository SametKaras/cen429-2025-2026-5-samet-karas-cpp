# Local Event Planner - Project Plan

## 📋 Project Information

**Project Title:** Local Event Planner - Secure C++ Console Application  
**Course:** CEN429 - Secure Programming  
**Academic Year:** 2025-2026  
**Team:** SametKaras  
**Repository:** [cen429-2025-2026-5-samet-karas-cpp](https://github.com/SametKaras/cen429-2025-2026-5-samet-karas-cpp)

---

## 🎯 Project Objectives

Develop a secure Local Event Planner console application in C++ that demonstrates:

1. **Core Functionality**: Event management system with attendee tracking, scheduling, and feedback collection
2. **Dynamic Library Architecture**: Implement core logic as a DLL (Dynamic Link Library)
3. **Comprehensive Security**: Apply industry-standard security measures including:
   - Data encryption (at rest and in transit)
   - Runtime Application Self-Protection (RASP)
   - Code hardening and obfuscation
   - Penetration testing and OWASP compliance
4. **Production-Grade Quality**: Full CI/CD pipeline, automated testing, and documentation

---

## 📅 Academic Calendar & Milestones

### Key Dates

| Date | Event | Milestone |
|------|-------|-----------|
| **04.10.2025** | Project Start | Project kickoff |
| **18.10.2025** | M0 Deadline | Project Plan & Approval |
| **31.10.2025** | M1 Deadline | Core Features & Basic Security |
| **07.11.2025** | **MIDTERM** | **M2: Vize Report & First Security Layer** |
| **15.01.2026** | M3 Deadline | Advanced Security & RASP |
| **02.02.2026** | **FINAL** | **M4: Final Report, Pentest & Testing** |

### Milestone Breakdown

#### M0: Project Plan & Approval (04.10 - 18.10) - 2 weeks
**Status:** In Progress  
**Deliverables:**
- ✅ Project plan document (this file)
- ✅ GitHub project board setup with milestone tracking
- ✅ Issue/PR templates
- 📋 CI/CD workflows (build, test, CodeQL)
- 📋 Branch protection rules
- 📋 Advisor approval confirmation

**Issues:** #1 - #6 (6 issues)

#### M1: Core Features & Basic Security (18.10 - 31.10) - 2 weeks
**Status:** Planned  
**Deliverables:**
- DLL project structure with CMake
- SQLite database with SQLCipher encryption
- Core event planner features (CRUD operations)
- User authentication system
- Basic input validation and sanitization
- Initial unit tests

**Issues:** #18 - #28 (11 issues)

#### M2: Midterm & First Security Layer (01.11 - 07.11) - 1 week
**Status:** Planned  
**Deliverables:**
- **Midterm Report** (07.11.2025)
- AES-256 encryption for sensitive data
- Secure password hashing (PBKDF2-SHA256)
- Input validation framework
- Code obfuscation (string hiding, control flow)
- Memory protection basics
- Session management

**Issues:** #29 - #36 (8 issues)

#### M3: Advanced Security & RASP (08.11 - 15.01) - 9 weeks
**Status:** Planned  
**Deliverables:**
- RASP implementation (anti-debug, anti-tamper)
- Whitebox cryptography (AES/DES)
- HSM integration (SoftHSM2)
- Memory protection (SafeStack/memguard)
- Hook detection and emulator detection
- Control flow integrity
- Asset management inventory

**Issues:** (7 issues - to be created)

#### M4: Testing, Pentest & Final Report (16.01 - 02.02) - 3 weeks
**Status:** Planned  
**Deliverables:**
- **Final Report** (02.02.2026)
- Comprehensive unit test suite (>80% coverage)
- Integration tests
- Penetration testing plan and execution
- OWASP Top 10 compliance verification
- Security audit documentation
- Final presentation materials

**Issues:** (4 issues - to be created)

---

## 🏗️ Technical Architecture

### System Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                  Local Event Planner App                     │
│                    (Console Interface)                       │
└───────────────────────┬─────────────────────────────────────┘
                        │
                        ▼
┌─────────────────────────────────────────────────────────────┐
│              LocalEventPlanner DLL (Core Logic)              │
├─────────────────────────────────────────────────────────────┤
│  • Event Management      • Security Layer                    │
│  • Attendee Tracking     • Encryption/Decryption             │
│  • Schedule Organizer    • Authentication/Authorization      │
│  • Feedback System       • RASP Protection                   │
└───────────┬────────────────────────┬────────────────────────┘
            │                        │
            ▼                        ▼
┌─────────────────────┐  ┌─────────────────────────────────┐
│  Encrypted SQLite   │  │   Security Components           │
│   (SQLCipher)       │  │  • Whitebox Crypto              │
│                     │  │  • Memory Guard                 │
│  • Events           │  │  • SoftHSM2                     │
│  • Attendees        │  │  • Anti-Tamper                  │
│  • Schedules        │  │  • Code Obfuscation             │
│  • Feedback         │  └─────────────────────────────────┘
│  • User Credentials │
└─────────────────────┘
```

### Technology Stack

| Component | Technology | Purpose |
|-----------|-----------|---------|
| **Language** | C++17/20 | Core development |
| **Build System** | CMake 3.20+ | Cross-platform build |
| **Database** | SQLite + SQLCipher | Encrypted data storage |
| **Cryptography** | OpenSSL, Whitebox AES/DES | Data encryption |
| **HSM** | SoftHSM2 | Key management |
| **Memory Protection** | Clang SafeStack, memguard | Memory security |
| **Testing** | Google Test (gtest) | Unit testing |
| **Coverage** | OpenCppCoverage, LCOV | Code coverage |
| **CI/CD** | GitHub Actions | Automation |
| **SAST** | CodeQL | Static analysis |
| **Documentation** | Doxygen, MkDocs | API & project docs |
| **Version Control** | Git + GitHub | Source control |

---

## 🎨 Feature Requirements

### Core Features (As per Assignment)

#### 1. Event Management
- **Create Event**: Add new events with details (name, date, location, description)
- **Edit Event**: Modify existing event information
- **Delete Event**: Remove events from the system
- **View Events**: List all events or filter by criteria
- **Event Categories**: Support multiple event types

#### 2. Attendee Management
- **Register Attendees**: Add attendee information
- **Track Registration**: Monitor registration status and payments
- **Attendee Lists**: View and export attendee lists
- **Ticket Management**: Assign and track ticket types
- **Check-in System**: Mark attendee presence at events

#### 3. Schedule Organizer
- **Session Planning**: Create event timelines and agendas
- **Activity Scheduling**: Plan workshops, performances, sessions
- **Resource Allocation**: Assign venues and resources
- **Timeline Visualization**: Display event schedules
- **Conflict Detection**: Prevent scheduling overlaps

#### 4. Feedback Collection
- **Post-Event Surveys**: Collect attendee feedback
- **Rating System**: Rate overall event satisfaction
- **Session Feedback**: Specific feedback for activities
- **Comment Collection**: Gather suggestions for improvement
- **Feedback Analysis**: Generate reports and statistics

#### 5. User Authentication (Optional but Recommended)
- **User Registration**: Create organizer accounts
- **Secure Login**: Password-based authentication
- **Session Management**: Maintain user sessions
- **Role-Based Access**: Different permission levels
- **Profile Management**: Edit user information

#### 6. Guest Mode (No Authentication)
- **Quick Access**: Allow usage without login
- **Limited Features**: Basic event viewing and feedback
- **Data Isolation**: Separate guest data from registered users

---

## 🔒 Security Requirements Checklist

### 1. Development Environment Security ✅

- [x] **Version Control**: Git with proper branching strategy
- [x] **Change Management**: GitHub Issues + Project Board
- [x] **Code Review**: PR templates and review process
- [x] **CI/CD Pipeline**: Automated builds and tests
- [x] **Signed Commits**: GPG signing (optional)
- [x] **Branch Protection**: Require PR reviews, status checks

### 2. Data Security at Runtime 📋

- [ ] **Memory Encryption**: Encrypt sensitive data in memory
- [ ] **Secure Memory Clearing**: Zero memory after use
- [ ] **Stack Protection**: Clang SafeStack implementation
- [ ] **Memory Guard**: memguard library integration
- [ ] **Buffer Overflow Protection**: Bounds checking

### 3. Data Security in Transit 📋

- [ ] **Session Key Management**: Encrypted session keys
- [ ] **Device Binding**: Tie sessions to specific devices
- [ ] **Payload Encryption**: AES-256 for transmitted data
- [ ] **Integrity Checks**: HMAC-SHA256 verification
- [ ] **Authentication Tags**: Message authentication codes
- [ ] **SSL/TLS**: Secure communication (if network features added)

### 4. Data Security at Rest 📋

- [ ] **Whitebox Cryptography**: Whitebox AES and DES
- [ ] **Database Encryption**: SQLCipher for SQLite
- [ ] **File Encryption**: Multiple encryption layers
- [ ] **Key Derivation**: PBKDF2 for password hashing
- [ ] **Encrypted Backups**: Secure data exports

### 5. Static Asset Protection 📋

- [ ] **Secret Keys**: Encrypted storage and access control
- [ ] **Hash Values**: Secure hash storage
- [ ] **Source Code**: Obfuscation and protection
- [ ] **Resources**: Encrypted resource files
- [ ] **Configuration**: Encrypted config files

### 6. Dynamic Asset Protection 📋

- [ ] **Device Fingerprinting**: Unique device identification
- [ ] **Session Data**: Encrypted session storage
- [ ] **Dynamic Keys**: Runtime key generation
- [ ] **Temporary Files**: Secure temp file handling
- [ ] **Cache Protection**: Encrypted cache data

### 7. Asset Management 📋

- [ ] **Asset Inventory**: Complete list of all sensitive assets
- [ ] **Asset Documentation**: Name, location, size, lifecycle
- [ ] **Protection Schema**: Confidentiality, integrity, authentication
- [ ] **Access Control**: Who can access what
- [ ] **Audit Trail**: Log access to sensitive assets

### 8. Interface Protection 📋

- [ ] **Input Validation**: Whitelist-based validation
- [ ] **Output Encoding**: Prevent injection attacks
- [ ] **API Security**: Secure internal DLL interfaces
- [ ] **Error Handling**: No information disclosure
- [ ] **Rate Limiting**: Prevent brute force (if applicable)

### 9. Code Hardening 📋

#### Obfuscation Techniques
- [ ] **Opaque Loops**: Complex loop structures
- [ ] **String Hiding**: Encrypt string literals
- [ ] **Function Name Mangling**: Hide function names
- [ ] **Control Flow Flattening**: Obscure execution flow
- [ ] **Dead Code Insertion**: Add non-functional code
- [ ] **Fake Branches**: Add decoy execution paths
- [ ] **Arithmetic Obfuscation**: Complex calculations
- [ ] **Boolean Obfuscation**: Hide true/false logic
- [ ] **Disable Logging**: Remove debug output in release

### 10. RASP (Runtime Application Self-Protection) 📋

#### Detection
- [ ] **Checksum Verification**: Verify code integrity
- [ ] **Signature Validation**: Check application signature
- [ ] **Debugger Detection**: Detect attached debuggers
- [ ] **Emulator Detection**: Identify virtual environments
- [ ] **Hook Detection**: Detect API hooking attempts
- [ ] **Root/Admin Detection**: Check elevated privileges
- [ ] **Tamper Detection**: Identify code modifications

#### Defense
- [ ] **Control Flow Obfuscation**: Hide execution paths
- [ ] **String/Resource Encryption**: Protect static data
- [ ] **Call Hiding**: Obscure function calls
- [ ] **Anti-Debug Tricks**: Prevent debugging

#### Deterrence
- [ ] **Self-Repair**: Attempt to fix tampering
- [ ] **Attack-Specific Responses**: React to threats
- [ ] **Graceful Degradation**: Safe failure modes
- [ ] **Exit Procedures**: Secure shutdown on threat

### 11. Memory Protection 📋

- [ ] **SafeStack**: Separate safe and unsafe stack
- [ ] **Guard Pages**: Memory boundary protection
- [ ] **ASLR**: Address Space Layout Randomization
- [ ] **DEP**: Data Execution Prevention
- [ ] **Secure Allocation**: Custom allocators
- [ ] **Memory Wiping**: Secure deallocation

### 12. Certificates & Communication 📋

- [ ] **SSL/TLS**: If network communication needed
- [ ] **Certificate Pinning**: Prevent MITM attacks
- [ ] **Mutual Authentication**: Two-way verification
- [ ] **Secure Protocols**: Use modern crypto standards

### 13. Security Certification & Testing 📋

- [ ] **OWASP Top 10 Compliance**: Verify against OWASP
- [ ] **Penetration Test Plan**: Detailed test scenarios
- [ ] **Penetration Test Execution**: Conduct tests
- [ ] **Vulnerability Assessment**: Identify weaknesses
- [ ] **Security Audit**: Third-party review (if possible)
- [ ] **Compliance Documentation**: ETSI/EMV/GSMA style docs

### 14. Binary Protection 📋

#### Detection Layer
- [ ] Checksum validation
- [ ] Anti-debug mechanisms
- [ ] Emulator detection
- [ ] Environment checks

#### Defense Layer
- [ ] Control flow obfuscation
- [ ] String/resource encryption
- [ ] Call hiding

#### Deterrence Layer
- [ ] Self-repair mechanisms
- [ ] Attack response strategies
- [ ] Secure shutdown procedures

---

## 📁 Project Structure

```
cen429-2025-2026-5-samet-karas-cpp/
│
├── .github/
│   ├── workflows/              # CI/CD pipelines
│   │   ├── build.yml           # Build and test
│   │   ├── codeql.yml          # Security analysis
│   │   └── coverage.yml        # Code coverage
│   ├── ISSUE_TEMPLATE/         # Issue templates
│   ├── pull_request_template.md
│   └── scripts/                # Automation scripts
│
├── src/
│   ├── localeventplanner/      # DLL library
│   │   ├── header/
│   │   │   ├── localeventplanner.h
│   │   │   ├── event.h
│   │   │   ├── attendee.h
│   │   │   ├── schedule.h
│   │   │   ├── feedback.h
│   │   │   ├── auth.h
│   │   │   └── security/       # Security headers
│   │   ├── src/
│   │   │   ├── event.cpp
│   │   │   ├── attendee.cpp
│   │   │   ├── schedule.cpp
│   │   │   ├── feedback.cpp
│   │   │   ├── auth.cpp
│   │   │   └── security/       # Security implementations
│   │   └── CMakeLists.txt
│   │
│   ├── localeventplannerapp/   # Console application
│   │   ├── header/
│   │   │   ├── localeventplannerapp.h
│   │   │   └── ui.h
│   │   ├── src/
│   │   │   ├── main.cpp
│   │   │   └── ui.cpp
│   │   └── CMakeLists.txt
│   │
│   ├── tests/                  # Unit tests
│   │   ├── localeventplanner/
│   │   │   ├── event_test.cpp
│   │   │   ├── attendee_test.cpp
│   │   │   ├── schedule_test.cpp
│   │   │   ├── feedback_test.cpp
│   │   │   └── security_test.cpp
│   │   └── CMakeLists.txt
│   │
│   └── utility/                # Helper utilities
│
├── docs/                       # Documentation
│   ├── plan.md                 # This file
│   ├── architecture.md         # System design
│   ├── security.md             # Security documentation
│   ├── api/                    # API documentation (Doxygen)
│   └── screenshots/            # Visual documentation
│
├── assets/                     # Project assets
│   ├── badges/                 # Coverage badges
│   └── logo.png
│
├── build/                      # Build output (gitignored)
├── report_test_hist_win/       # Test reports (Windows)
├── report_test_hist_linux/     # Test reports (Linux)
│
├── CMakeLists.txt              # Root CMake
├── README.md                   # Project overview
├── .gitignore
└── *.bat / *.sh                # Build scripts

```

---

## 🧪 Testing Strategy

### Unit Testing
- **Framework**: Google Test (gtest/gmock)
- **Coverage Target**: Minimum 80% line coverage
- **Scope**: All DLL functions and classes
- **Automation**: Run on every commit via CI/CD

### Integration Testing
- **Scope**: DLL + Database integration
- **Database Tests**: CRUD operations with SQLCipher
- **Security Tests**: Encryption/decryption workflows

### Security Testing
- **Static Analysis**: CodeQL on every PR
- **Dynamic Analysis**: Runtime checks during tests
- **Penetration Testing**: Manual security assessment
- **Vulnerability Scanning**: Automated dependency checks

### Test Coverage Requirements
| Component | Line Coverage | Branch Coverage |
|-----------|---------------|-----------------|
| Core DLL | ≥80% | ≥70% |
| Security Module | ≥90% | ≥80% |
| Console App | ≥60% | ≥50% |

---

## 🔄 Development Workflow

### Git Workflow
```
main (protected)
  └── feature/M1-* (feature branches)
  └── feature/M2-* (feature branches)
  └── bugfix/* (bugfix branches)
  └── security/* (security feature branches)
```

### Branch Protection Rules
- ✅ Require pull request reviews (1 minimum)
- ✅ Require status checks to pass (build, tests, CodeQL)
- ✅ Require linear history
- ✅ Include administrators
- ❌ Allow force pushes (disabled)
- ❌ Allow deletions (disabled)

### Commit Message Convention
```
type(scope): subject

[optional body]

[optional footer]
```

**Types:** `feat`, `fix`, `docs`, `style`, `refactor`, `test`, `chore`, `security`

**Examples:**
- `feat(event): add event creation with validation`
- `security(crypto): implement whitebox AES encryption`
- `fix(attendee): resolve duplicate registration bug`
- `docs(readme): update installation instructions`

---

## 📊 Progress Tracking

### GitHub Project Board
- **URL**: https://github.com/users/SametKaras/projects/4
- **Views**:
  - **Board View**: Kanban-style workflow (Backlog → Ready → In Progress → Review → Testing → Done)
  - **Milestone View**: Group by M0/M1/M2/M3/M4
  - **Priority View**: Group by priority labels

### Labels
- **Priority**: `priority:P0` (critical) → `priority:P3` (low)
- **Type**: `bug`, `feature`, `security`, `documentation`
- **Area**: `area:core`, `area:security`, `area:database`, `area:testing`
- **Milestone**: `M0`, `M1`, `M2`, `M3`, `M4`

### Metrics
- Issues closed per milestone
- Code coverage percentage
- Security vulnerabilities found/fixed
- Documentation coverage

---

## 📚 Documentation Plan

### Code Documentation
- **Tool**: Doxygen
- **Format**: JavaDoc-style comments
- **Coverage Target**: 100% of public APIs
- **Generate**: Automatically via build scripts

### Project Documentation
- **Tool**: MkDocs
- **Hosting**: GitHub Pages
- **Content**:
  - Architecture overview
  - API reference
  - Security documentation
  - Developer guide
  - User guide

### Reports
1. **Midterm Report** (07.11.2025)
   - Progress summary
   - Implemented features
   - Security measures applied
   - Challenges and solutions
   - Next steps

2. **Final Report** (02.02.2026)
   - Complete project documentation
   - All security implementations
   - Test results and coverage
   - Penetration test findings
   - OWASP compliance verification
   - Lessons learned

---

## 🎓 Learning Objectives & Skills

### Technical Skills
- ✅ C++ advanced programming (C++17/20)
- ✅ CMake build system configuration
- ✅ Dynamic library (DLL) development
- ✅ SQLite database with encryption (SQLCipher)
- ✅ Cryptographic implementations
- ✅ Memory management and protection
- ✅ Unit testing with Google Test
- ✅ CI/CD with GitHub Actions

### Security Skills
- 🔒 Secure coding practices
- 🔒 Encryption and hashing algorithms
- 🔒 RASP techniques
- 🔒 Code obfuscation
- 🔒 Penetration testing
- 🔒 OWASP Top 10 awareness
- 🔒 Vulnerability assessment
- 🔒 Security certification processes

### Software Engineering
- 📋 Agile project management
- 📋 Version control with Git
- 📋 Code review processes
- 📋 Automated testing
- 📋 Documentation best practices
- 📋 Requirements analysis

---

## ⚠️ Risks and Mitigation

| Risk | Probability | Impact | Mitigation |
|------|-------------|--------|------------|
| **Time constraints** | High | High | Start early, prioritize M0/M1/M2 |
| **Security complexity** | Medium | High | Break into smaller tasks, research early |
| **SQLCipher integration** | Medium | Medium | Test early, have fallback (plain SQLite) |
| **SoftHSM2 setup** | Medium | Medium | Docker container, documentation |
| **Cross-platform issues** | Low | Medium | Focus on Windows, test incrementally |
| **Scope creep** | Medium | High | Stick to defined issues, no extras |

---

## 🎯 Success Criteria

### M0 Success (18.10.2025)
- ✅ Project plan approved by advisor
- ✅ GitHub infrastructure complete
- ✅ CI/CD pipelines functional

### M1 Success (31.10.2025)
- ✅ DLL compiles and links successfully
- ✅ Basic CRUD operations work
- ✅ Unit tests pass (≥60% coverage)
- ✅ Authentication system functional

### M2 Success (07.11.2025) - MIDTERM
- ✅ **Midterm report submitted**
- ✅ Encrypted database operational
- ✅ Password hashing implemented
- ✅ Basic obfuscation applied
- ✅ ≥70% test coverage

### M3 Success (15.01.2026)
- ✅ RASP features implemented
- ✅ Whitebox crypto integrated
- ✅ Memory protection active
- ✅ HSM integration complete
- ✅ ≥80% test coverage

### M4 Success (02.02.2026) - FINAL
- ✅ **Final report submitted**
- ✅ Penetration tests completed
- ✅ OWASP compliance verified
- ✅ All security requirements met
- ✅ ≥85% test coverage
- ✅ Complete documentation

---

## 📞 Advisor Communication Plan

### Communication Schedule
- **Weekly Updates**: Via GitHub commit activity
- **Milestone Reviews**: At each milestone deadline
- **Issue Escalation**: As needed via email/meeting

### Deliverables for Advisor
1. **This Project Plan** (18.10.2025) - Awaiting approval
2. **Midterm Report** (07.11.2025) - PDF + presentation
3. **Final Report** (02.02.2026) - PDF + presentation + demo

### Questions for Advisor
- [ ] Is SQLite + SQLCipher acceptable for the database requirement?
- [ ] Can we use SoftHSM2 for HSM integration instead of hardware HSM?
- [ ] Should we implement network features for SSL/TLS demonstration?
- [ ] Is Windows-only development acceptable, or cross-platform required?
- [ ] Any specific security frameworks/libraries recommended?

---

## 🔗 References

### Security Standards
- OWASP Top 10: https://owasp.org/www-project-top-ten/
- OWASP Mobile Security: https://owasp.org/www-project-mobile-security/
- CWE Top 25: https://cwe.mitre.org/top25/

### Documentation
- Google Test: https://google.github.io/googletest/
- CMake: https://cmake.org/documentation/
- SQLCipher: https://www.zetetic.net/sqlcipher/
- SoftHSM2: https://www.opendnssec.org/softhsm/
- Doxygen: https://www.doxygen.nl/

### Cryptography
- OpenSSL: https://www.openssl.org/
- Whitebox Crypto: Academic papers and implementations

---

## ✅ Approval Section

**Student:** SametKaras  
**Date Submitted:** _______________  
**Version:** 1.0

**Advisor Approval:**

Name: _______________________  
Signature: ___________________  
Date: _______________________  
Comments: ____________________  
____________________________  
____________________________  

---

**Document Status:** Draft - Awaiting Advisor Approval  
**Last Updated:** 19.10.2025  
**Next Review:** Upon advisor feedback

