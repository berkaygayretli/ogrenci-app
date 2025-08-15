# Öğrenci Yönetim Sistemi / Student Management System

Bu proje, **C++ ile yazılmış bir konsol tabanlı öğrenci yönetim sistemidir**.  
Öğrencilerin isim, soyisim, öğrenci numarası ve not bilgilerini saklamanıza, listelemenize, silmenize ve güncellemenize olanak sağlar.

This project is a **console-based student management system written in C++**.  
It allows you to store, list, delete, and update student information such as name, surname, student ID, and grades.

## Özellikler / Features
- Öğrenci ekleme / Add student (benzersiz öğrenci numarası ile / with unique student ID)  
- Öğrenci listesi görüntüleme / List students  
- Öğrenci silme / Remove student  
- Öğrenci bilgilerini güncelleme / Update student  
- Türkçe ve İngilizce dil desteği / Turkish and English language support

## Kullanım / Usage
1. Programı derleyin (ör: `g++ main.cpp -o ogrenci.exe`)  
2. Konsolda çalıştırın (`./ogrenci.exe`)  
3. Menüde yapmak istediğiniz işlemin numarasını girin  
4. Çıkmak için menüden "Çıkış / Exit" seçeneğini seçin

## Not / Note
- Öğrenci numarası **benzersizdir** (primary key gibi davranır).  
- Notlar, her öğrencinin kendi vektöründe saklanır.  
