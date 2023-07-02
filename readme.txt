BIL461 HOMEWORK2 

Ödevi yaparken hem ayran evresi hem de chopstick alma olayları için 2 tane semafor oluşturdum. 
2 durum için ayrı ayrı take put ve test methodları yazdım. 
Testte yemek yeme durumunda sağ ve sol filozof kontrolü yaptım, ayran alma durumunda tüm filozoflar teker tekr kontrol ettim. 

Çıktı olarak garsonun ne kadar ayran getirdiği ve her filozofun ne kadar ayran içtiğini yazdırdım.
Her tur sonunda 5 saniyelik gecikme konuldu.  
! Kod içinde yorum satırına aldığım printf() satırları var. Onlar sayesinde tüm filozofların hangi adımda ne yaptığı kontrolü sağlandı. 

Başta ayranları yemeği tüm filozoflar karışık yiyor. Fakat sonrasında tas sırası beklerken öncelik sırası belirlenmediği için 
sadece for döngüsü ile tas birinde mi değil mi bakıldığı için starvation problemi ortaya çıkmaya başlıyor.Kod çıktısı incelendiğinde bu problem
hep olmuyor olursa sonrasında düzelip geri aynı sıkıntıyı yaşadığı oluyor.  


NASIL ÇALIŞIR ?
Terminale çalıştırmak istediğimiz filozof sayısı argüman olarak verilir.
-> gcc -pthread 191101053_hw2.c -o hw2
-> ./hw2 <input_sayi>

!! Programı sonlandırmak için terminalde CTRL C işlemi yapılması gerekmektedir. 

Hira Cansu Değirmenbaşı
191101053
