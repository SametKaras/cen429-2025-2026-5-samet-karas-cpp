# 🚀 GitHub Project Setup - Kullanım Rehberi

Bu rehber, Local Event Planner projesinin GitHub'a nasıl kurulacağını adım adım açıklar.

## 📋 Gereksinimler

1. **GitHub CLI** kurulu olmalı
2. GitHub hesabınıza giriş yapmış olmalısınız
3. PowerShell (Windows) veya Bash (Linux/Mac)

## 🛠️ Kurulum Adımları

### Adım 1: GitHub CLI Kurulumu

#### Windows:
```powershell
# winget ile
winget install --id GitHub.cli

# VEYA Chocolatey ile
choco install gh
```

#### Linux:
```bash
# Ubuntu/Debian
sudo apt install gh

# Fedora
sudo dnf install gh
```

### Adım 2: GitHub'a Giriş

```bash
gh auth login
```

- **What account do you want to log into?** → GitHub.com
- **What is your preferred protocol?** → HTTPS
- **Authenticate Git with your GitHub credentials?** → Yes
- **How would you like to authenticate?** → Login with a web browser

### Adım 3: Script'leri Çalıştırma

#### Windows (PowerShell):

```powershell
# 1. Script klasörüne git
cd .github/scripts

# 2. Execution policy değiştir (gerekirse)
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser

# 3. İlk kurulum (M0 + labels + milestones)
.\setup-project.ps1

# 4. Tüm issue'ları oluştur (M1, M2, M3, M4)
.\create-all-issues.ps1
```

#### Linux/Mac (Bash):

```bash
# 1. Script klasörüne git
cd .github/scripts

# 2. Script'leri çalıştırılabilir yap
chmod +x setup-project.sh create-all-issues.sh

# 3. İlk kurulum
./setup-project.sh

# 4. Tüm issue'ları oluştur
./create-all-issues.sh
```

## ✅ Kurulum Sonrası Kontrol

### GitHub'da kontrol edin:

1. **Labels** → `https://github.com/yourusername/yourrepo/labels`
   - 21 adet label olmalı

2. **Milestones** → `https://github.com/yourusername/yourrepo/milestones`
   - M0, M1, M2, M3, M4 olmalı

3. **Issues** → `https://github.com/yourusername/yourrepo/issues`
   - M0 için 6 issue
   - M1 için 11 issue
   - Toplamda 17+ issue olmalı

## 🎯 Sonraki Adımlar

1. **Project Board Oluştur** (Issue 0.2)
   - GitHub → Projects → New Project
   - Board view seç
   - Kolonlar: Backlog, Ready, In Progress, In Review, Testing, Done

2. **CI/CD Workflow'larını Ekle** (Issue 0.3)
   - `.github/workflows/build.yml`
   - `.github/workflows/codeql.yml`

3. **Branch Protection Aktif Et** (Issue 0.4)
   - Settings → Branches → Add rule
   - Branch name pattern: `main`
   - Require pull request reviews
   - Require signed commits

## 🔍 Sorun Giderme

### Problem: "gh: command not found"
**Çözüm:** GitHub CLI kurulu değil, yukarıdaki kurulum adımlarını izleyin.

### Problem: "authentication failed"
**Çözüm:** 
```bash
gh auth logout
gh auth login
```

### Problem: "milestone already exists"
**Çözüm:** Script'i tekrar çalıştırırsanız hata verebilir. Önce mevcut milestone'ları silin veya script'te `--force` flag'i kullanın.

### Problem: PowerShell execution policy
**Çözüm:**
```powershell
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
```

## 📞 Yardım

Sorun yaşarsanız:
1. GitHub Issues'a bakın
2. Discord/Slack kanalında sorun
3. Script loglarını kontrol edin

## 📝 Not

Bu script'ler projenin başlangıcında bir kez çalıştırılmalıdır. Sonradan manuel olarak issue ekleyebilir, düzenleyebilirsiniz.

