# Local Event Planner - GitHub Project Setup Script
# Bu script tüm milestone, label ve issue'ları otomatik oluşturur

# Renkler için yardımcı fonksiyon
function Write-ColorOutput($ForegroundColor) {
    $fc = $host.UI.RawUI.ForegroundColor
    $host.UI.RawUI.ForegroundColor = $ForegroundColor
    if ($args) {
        Write-Output $args
    }
    $host.UI.RawUI.ForegroundColor = $fc
}

Write-ColorOutput Green "🚀 Local Event Planner - GitHub Project Setup"
Write-ColorOutput Green "================================================"

# GitHub CLI kurulu mu kontrol et
if (-not (Get-Command gh -ErrorAction SilentlyContinue)) {
    Write-ColorOutput Red "❌ GitHub CLI (gh) kurulu değil!"
    Write-ColorOutput Yellow "Lütfen önce şu komutu çalıştırın: winget install --id GitHub.cli"
    exit 1
}

# GitHub'a giriş yapılmış mı kontrol et
$authStatus = gh auth status 2>&1
if ($LASTEXITCODE -ne 0) {
    Write-ColorOutput Red "❌ GitHub'a giriş yapılmamış!"
    Write-ColorOutput Yellow "Lütfen önce şu komutu çalıştırın: gh auth login"
    exit 1
}

Write-ColorOutput Green "✅ GitHub CLI hazır"
Write-ColorOutput Cyan "`n📋 1. LABEL'LARI OLUŞTURUYOR..."

# Label'ları oluştur
$labels = @(
    @{name="type:feature"; color="0e8a16"; description="Yeni özellik"},
    @{name="type:security"; color="d93f0b"; description="Güvenlik ile ilgili"},
    @{name="type:docs"; color="0075ca"; description="Dokümantasyon"},
    @{name="type:test"; color="fbca04"; description="Test ile ilgili"},
    @{name="type:bug"; color="d73a4a"; description="Hata"},
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
    @{name="priority:P0"; color="b60205"; description="Blocker - Kritik"},
    @{name="priority:P1"; color="d93f0b"; description="High - Yüksek öncelik"},
    @{name="priority:P2"; color="fbca04"; description="Medium - Orta öncelik"},
    @{name="priority:P3"; color="0e8a16"; description="Low - Düşük öncelik"}
)

foreach ($label in $labels) {
    Write-Host "  Creating label: $($label.name)" -ForegroundColor Gray
    gh label create $label.name --color $label.color --description $label.description --force 2>&1 | Out-Null
}

Write-ColorOutput Green "✅ Label'lar oluşturuldu ($($labels.Count) adet)"

Write-ColorOutput Cyan "`n🎯 2. MILESTONE'LARI OLUŞTURUYOR..."

# Milestone'lari olustur
$milestones = @(
    @{
        title="M0 - Proje Plani ve Onay"
        due="2024-10-10"
        description="Amac: GitHub repo kurulumunu, proje planini ve guvenlik politikalarini hazirlamak.`nKriter: CI, CodeQL ve Project board calisir durumda olmali."
    },
    @{
        title="M1 - Cekirdek Islevler ve Temel Guvenlik"
        due="2024-11-05"
        description="Amac: Temel uygulama iskeleti, CRUD islemleri, SQLite baglantisi ve test altyapisi.`nKriter: Event, Attendee, Schedule ve Feedback modulleri DLL uzerinden calismali."
    },
    @{
        title="M2 - Vize ve Ilk Guvenlik Katmani"
        due="2024-11-07"
        description="Amac: Kullanimda veri guvenligi, sifreleme ve Vize raporu teslimi.`nKriter: Bellek koruma ve veri sifreleme fonksiyonlari calisir durumda olmali."
    },
    @{
        title="M3 - Gelismis Guvenlik RASP ve Sertlestirme"
        due="2024-12-31"
        description="Amac: Veri koruma, sertifika dogrulama, RASP ve kod sertlestirme.`nKriter: Tum guvenlik katmanlari aktif; uygulama anti-debug ve checksum dogrulamasina sahip."
    },
    @{
        title="M4 - Testler Pentest ve Final Raporu"
        due="2025-02-02"
        description="Amac: Tum sistemin test edilmesi, pentest planinin uygulanmasi ve final teslim.`nKriter: %80+ test kapsami, pentest plani tamam, final raporu ve sunum hazirlanmis."
    }
)

foreach ($ms in $milestones) {
    Write-Host "  Creating milestone: $($ms.title)" -ForegroundColor Gray
    gh milestone create $ms.title --due $ms.due --description $ms.description 2>&1 | Out-Null
}

Write-ColorOutput Green "✅ Milestone'lar oluşturuldu ($($milestones.Count) adet)"

Write-ColorOutput Cyan "`n📝 3. ISSUE'LARI OLUŞTURUYOR..."

# M0 Issues
$m0Issues = @(
    @{
        title="Issue 0.1 - Proje Planinin Eklenmesi"
        body=@"
## Aciklama
Hazirlanan proje plani (docs/plan.md) dosyasi repoya eklenmeli ve commitlenmeli.

## Cikti
- [ ] docs/plan.md dosyasi olusturuldu
- [ ] Commit log'da imzali commit: feat(docs): add project plan
- [ ] Milestone ve issue listesi eklendi

## Kabul Kriterleri
- Proje plani markdown formatinda
- Tum milestone'lar detaylandirilmis
- Issue'lar acikca tanimlanmis
"@
        labels="type:docs,priority:P1"
        milestone="M0 - Proje Plani ve Onay"
    },
    @{
        title="Issue 0.2 - GitHub Project Board Kurulumu"
        body=@"
## Aciklama
Project view olusturulacak; kolonlar: Backlog, Ready, In Progress, In Review, Testing, Done

## Cikti
- [ ] GitHub Projects board olusturuldu
- [ ] Kolonlar tanimlandi
- [ ] Board linki ve screenshot proje planina eklendi

## Kabul Kriterleri
- Board'da tum issue'lar gorunuyor
- Otomatik kart ekleme aktif
- Workflow automation kurulu
"@
        labels="type:docs,area:management"
        milestone="M0 - Proje Plani ve Onay"
    },
    @{
        title="Issue 0.3 - CI and CodeQL Kurulumu"
        body=@"
## Aciklama
- .github/workflows/build.yml (CMake build + CTest)
- .github/workflows/codeql.yml kurulacak, CodeQL guvenlik taramasi calismali

## Cikti
- [ ] build.yml workflow eklendi
- [ ] codeql.yml workflow eklendi
- [ ] CI workflow'lari yesil geciyor

## Kabul Kriterleri
- CMake build basarili
- Test suite calisiyor
- CodeQL security scanning aktif
"@
        labels="type:security,area:ci"
        milestone="M0 - Proje Plani ve Onay"
    },
    @{
        title="Issue 0.4 - Branch Protection ve Signed Commits"
        body=@"
## Aciklama
main branch korumali olacak, squash merge ve imzali commit zorunlu hale getirilecek.

## Cikti
- [ ] Branch protection rules aktif
- [ ] Require signed commits enabled
- [ ] Require pull request reviews
- [ ] Require status checks

## Kabul Kriterleri
- Dogrudan main'e push engellenmis
- PR approval zorunlu
- GPG signed commits zorunlu
"@
        labels="type:security,priority:P2"
        milestone="M0 - Proje Plani ve Onay"
    },
    @{
        title="Issue 0.5 - Label Set ve Issue Sablonlari"
        body=@"
## Aciklama
Etiket seti ve issue/pr sablonlari .github/ISSUE_TEMPLATE/ dizinine eklenecek.

## Cikti
- [ ] Issue templates olusturuldu
- [ ] PR template eklendi
- [ ] Tum label'lar tanimlandi

## Kabul Kriterleri
- Feature request template
- Bug report template
- Security issue template
- PR template with checklist
"@
        labels="type:docs,area:management"
        milestone="M0 - Proje Plani ve Onay"
    },
    @{
        title="Issue 0.6 - Onay Talebi"
        body=@"
## Aciklama
Proje plani, GitHub project ve workflow ekran goruntuleriyle birlikte onay icin danismana gonderilecek.

## Cikti
- [ ] Proje plani PDF olarak hazirlandi
- [ ] Screenshots eklendi
- [ ] Onay talebi e-postasi gonderildi
- [ ] Proje plani onaylandi cevabi alindi

## Kabul Kriterleri
- Danisman onayi alinmis
- Feedback'ler uygulanmis
"@
        labels="type:docs,priority:P1"
        milestone="M0 - Proje Plani ve Onay"
    }
)

Write-ColorOutput Yellow "`nM0 Issue'ları oluşturuluyor..."
foreach ($issue in $m0Issues) {
    Write-Host "  Creating: $($issue.title)" -ForegroundColor Gray
    gh issue create --title $issue.title --body $issue.body --label $issue.labels --milestone $issue.milestone 2>&1 | Out-Null
}

Write-ColorOutput Green "✅ Issue'lar oluşturuldu"
Write-ColorOutput Cyan "`n============================================"
Write-ColorOutput Green "🎉 KURULUM TAMAMLANDI!"
Write-ColorOutput Cyan "`nOluşturulan kaynaklar:"
Write-ColorOutput White "  - $($labels.Count) adet label"
Write-ColorOutput White "  - $($milestones.Count) adet milestone"
Write-ColorOutput White "  - $($m0Issues.Count) adet issue (M0)"
Write-ColorOutput Cyan "`n📌 Sonraki adımlar:"
Write-ColorOutput White "  1. GitHub'da Issues sekmesini kontrol edin"
Write-ColorOutput White "  2. Project board'u kurun (Issue 0.2)"
Write-ColorOutput White "  3. M1, M2, M3, M4 issue'larını oluşturmak için:"
Write-ColorOutput Yellow "     .\\.github\\scripts\\create-all-issues.ps1"

Write-ColorOutput Cyan "`n🔗 Linkler:"
$repoUrl = gh repo view --json url -q .url
Write-ColorOutput White "  Issues: $repoUrl/issues"
Write-ColorOutput White "  Milestones: $repoUrl/milestones"
Write-ColorOutput White "  Projects: $repoUrl/projects"

