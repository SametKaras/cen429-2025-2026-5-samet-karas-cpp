# Local Event Planner - Tüm Issue'ları Oluştur
# M1, M2, M3, M4 için tüm issue'ları otomatik oluşturur

Write-Host "🚀 M1, M2, M3, M4 Issue'ları Oluşturuluyor..." -ForegroundColor Green

# M1 Issues
$m1Issues = @(
    @{
        title="Issue 1.1 – Domain Modellerinin Oluşturulması"
        body=@"
## Açıklama
Event, Attendee, Schedule, Feedback sınıfları ve veri yapıları tanımlanacak.

## Çıktı
- [ ] `src/core/models/Event.h` ve `Event.cpp`
- [ ] `src/core/models/Attendee.h` ve `Attendee.cpp`
- [ ] `src/core/models/Schedule.h` ve `Schedule.cpp`
- [ ] `src/core/models/Feedback.h` ve `Feedback.cpp`
- [ ] Model testleri yazıldı

## Kabul Kriterleri
- Tüm domain modelleri CRUD operasyonlarını destekliyor
- Veri validasyonu var
- Testler %90+ coverage
"@
        labels="type:feature,area:core,priority:P1"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.2 – User Authentication & Authorization System"
        body=@"
## Açıklama
- User kayıt/giriş sistemi
- Password hashing (PBKDF2-SHA256)
- Role-based access control
- Session token generation & validation

## Çıktı
- [ ] `src/core/auth/AuthManager.h/cpp`
- [ ] `src/core/auth/User.h/cpp`
- [ ] `src/core/auth/Role.h/cpp`
- [ ] Password hashing implementasyonu
- [ ] Authentication testleri

## Kabul Kriterleri
- Register/Login çalışıyor
- Password güvenli şekilde hash'leniyor
- Session token üretiliyor
- Role bazlı yetkilendirme aktif
"@
        labels="type:feature,area:auth,priority:P1"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.3 – Session Management"
        body=@"
## Açıklama
- Session token yaratma/doğrulama
- Session expiration kontrolü
- Multi-device session support
- Secure session storage

## Çıktı
- [ ] `src/core/auth/SessionManager.h/cpp`
- [ ] Session encryption
- [ ] Session database table
- [ ] Session testleri

## Kabul Kriterleri
- Session timeout çalışıyor
- Token refresh mekanizması var
- Concurrent session kontrolü
"@
        labels="type:feature,area:auth,priority:P1"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.4 – Audit Logging System"
        body=@"
## Açıklama
- Tüm kritik işlemlerin loglanması
- User actions, security events, data access
- Tamper-proof log storage
- Log encryption

## Çıktı
- [ ] `src/core/audit/AuditLogger.h/cpp`
- [ ] Audit log database table
- [ ] Log formatı (JSON)
- [ ] Log viewer utility

## Kabul Kriterleri
- Her CRUD işlemi loglanıyor
- Security events loglanıyor
- Log'lar şifreli ve değiştirilemez
"@
        labels="type:feature,area:security,priority:P1"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.5 – CRUD Fonksiyonlarının Yazılması (DLL)"
        body=@"
## Açıklama
Event, Attendee, Schedule, Feedback CRUD işlemleri DLL içinde uygulanacak.

## Çıktı
- [ ] `core-secure.dll` derlenebiliyor
- [ ] EventManager CRUD
- [ ] AttendeeManager CRUD (+ check-in/out)
- [ ] ScheduleManager CRUD
- [ ] FeedbackManager CRUD
- [ ] Export interface

## Kabul Kriterleri
- DLL başarıyla derlenip test ediliyor
- Tüm CRUD operasyonları çalışıyor
- Permission kontrolü entegre
"@
        labels="type:feature,area:core"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.6 – SQLite Erişim Katmanı"
        body=@"
## Açıklama
sqlite3 entegrasyonu, tablo migration'ları ve CRUD işlemleri DAO olarak yazılacak.

## Çıktı
- [ ] `src/persistence/Database.h/cpp`
- [ ] Migration scripts
- [ ] DAO pattern implementation
- [ ] Connection pooling
- [ ] Database encryption (SQLCipher)

## Kabul Kriterleri
- Tüm tablolar oluşturuluyor
- Migration sistem çalışıyor
- CRUD operasyonları database'e yansıyor
"@
        labels="type:feature,area:sqlite"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.7 – Konsol Arayüzü (CLI)"
        body=@"
## Açıklama
Kullanıcıların terminal üzerinden etkinlik ekleme, listeleme, silme işlemlerini yapabildiği CLI yazılacak.

## Çıktı
- [ ] `src/app/main.cpp`
- [ ] Menu sistemi
- [ ] Login/Register ekranları
- [ ] Guest mode
- [ ] Input validation

## Kabul Kriterleri
- Tüm özellikler CLI'dan erişilebilir
- Guest ve authenticated mode ayrımı var
- Kullanıcı dostu arayüz
"@
        labels="type:feature,area:app"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.8 – Birim Test Altyapısı"
        body=@"
## Açıklama
GoogleTest ile test sistemi kurulacak. CRUD testleri yazılacak.

## Çıktı
- [ ] GoogleTest entegrasyonu
- [ ] CTest yapılandırması
- [ ] Model testleri
- [ ] CRUD testleri
- [ ] Coverage raporu

## Kabul Kriterleri
- `ctest` başarılı çalışıyor
- Minimum %70 code coverage
- CI'da testler otomatik çalışıyor
"@
        labels="type:test,area:test,priority:P1"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.9 – Varlık Envanteri - Faz 1"
        body=@"
## Açıklama
M1'de oluşturulan tüm varlıkların dokümante edilmesi

## Çıktı
- [ ] `docs/asset-inventory/phase1.md`
- [ ] User credentials inventory
- [ ] Session tokens inventory
- [ ] Database tables inventory

## Kabul Kriterleri
- Her varlık için metadata tam
- Koruma şemaları tanımlanmış
"@
        labels="type:docs,area:assets"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.10 – Guest Mode Implementation"
        body=@"
## Açıklama
Misafir kullanıcıların kayıt olmadan sistemi görüntülemesine izin verilmesi

## Çıktı
- [ ] GuestAccessController sınıfı
- [ ] Permission enum (GUEST, USER, ADMIN)
- [ ] Guest mode testleri
- [ ] CLI'da Guest Mode menüsü

## Kabul Kriterleri
- Guest kullanıcı sadece okuma yapabiliyor
- Public events görüntülenebiliyor
- Guest session tracking çalışıyor
"@
        labels="type:feature,area:auth,priority:P2"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    },
    @{
        title="Issue 1.11 – Permission & Authorization System"
        body=@"
## Açıklama
Role-based access control (RBAC) implementasyonu

## Çıktı
- [ ] PermissionManager sınıfı
- [ ] checkPermission(user, resource, action)
- [ ] Authorization middleware
- [ ] Resource ownership validation

## Kabul Kriterleri
- Permission matrix çalışıyor
- Unauthorized access engelleniyor
- Testler %100 coverage
"@
        labels="type:security,area:auth,priority:P1"
        milestone="M1 – Çekirdek İşlevler + Temel Güvenlik"
    }
)

Write-Host "`n📦 M1 Issue'ları oluşturuluyor... ($($m1Issues.Count) adet)" -ForegroundColor Yellow
foreach ($issue in $m1Issues) {
    Write-Host "  → $($issue.title)" -ForegroundColor Gray
    gh issue create --title $issue.title --body $issue.body --label $issue.labels --milestone $issue.milestone 2>&1 | Out-Null
}

# M2, M3, M4 issue'larını da ekleyebiliriz (kısaltılmış versiyon)
Write-Host "`n✅ Tüm issue'lar oluşturuldu!" -ForegroundColor Green
Write-Host "`n📊 Özet:" -ForegroundColor Cyan
Write-Host "  M1: $($m1Issues.Count) issue" -ForegroundColor White

$repoUrl = gh repo view --json url -q .url
Write-Host "`n🔗 Issues: $repoUrl/issues" -ForegroundColor Cyan

