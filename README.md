# RFC 9213 Tabanlı HTTP Öncelik Yönetim Sistemi (Gateway)

Bu proje, modern ağ protokollerinden biri olan **RFC 9213 (Extensible Priorities for HTTP)** standartlarını temel alarak geliştirilmiş bir öncelikli istek yönetim simülasyonudur. Sistem, gelen ağ paketlerini (request) sahip oldukları öncelik değerlerine göre sıraya dizer ve en yüksek önceliğe sahip olanı ilk sırada işler.

## 🛠️ Teknik Mimari

Proje, düşük gecikme ve yüksek performans hedefleyen modüler bir C mimarisi ile inşa edilmiştir:

*   **Veri Yapısı:** Önceliklerin yönetiminde **Min-Heap** tabanlı bir **Priority Queue** (Öncelikli Kuyruk) kullanılmıştır.
*   **Karmaşıklık:** Ekleme (Push) ve Çıkarma (Pop) işlemleri $O(\log n)$ zaman karmaşıklığı ile optimize edilmiştir.
*   **RFC 9213 Entegrasyonu:** HTTP isteklerinde yer alan `u=0` (En Yüksek) ile `u=7` (En Düşük) arasındaki öncelik değerlerini ayrıştıran özel bir parser içermektedir.

## 📂 Dosya Yapısı

*   **main.c**: Sistemin test senaryolarını yürüten ana giriş noktası.
*   **priority_queue.h / .c**: Heap veri yapısının mantıksal tanımlamaları ve dinamik bellek yönetimi.
*   **rfc_parser.h / .c**: RFC standartlarındaki öncelik stringlerini sayısal verilere dönüştüren motor.

## 🚀 Kurulum ve Çalıştırma

### 1. Terminal Üzerinden Derleme (GCC)
Klasör içerisinde terminali açarak (CMD) aşağıdaki komutu uygulayınız:
```bash
gcc main.c priority_queue.c rfc_parser.c -o gateway_system
