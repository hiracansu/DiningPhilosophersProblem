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




Konu: C, Unix/Linux Multithreading, Pthreads, Process Synchronization
Görev: Meşhur Dining Philosophers problemi yeme-düşünme döngüsünden oluşmaktadır. Bunun yerli versiyonunda birde içecek (Ayran) servisi olsun. Süreç 3 aşamalıdır: ayran alma, pilav yeme ve düşünme (yemek sonrası çay servisi şimdilik yok, o seneye olur belki).
Her filozof yemek masasına elinde 1 tas ayran olmadan geçemesin ve yemek sırasında tasdaki ayranın hepsini içsin. Yalnız, ortalıkta tek bir ayran sürahisi olsun ve aynı anda yalnız bir filozof bu sürahiden ayranı kendi tasına koyabilsin. Filozof sayısına N diyelim. Garson bittikçe sürahiye K taslık (1 <=K<=5N arasında rasgele bir değer) ayran koysun. Sürahi bitene kadar geçen süreye bir tur diyelim. Her turda bir filozof birden fazla sayıda porsiyon yiyebilir.
Bu süreci simüle eden bir C programı yazın. Program başlangıçta N sayısını alacak ve turlara ctrl-C ye basılana kadar devam edecektir. Her tur sonunda K değeri ve hangi filozof o turda kaç porsiyon yedi yazdırılacaktır. Her tur arasına akışı izleyebilmek adına 5 saniye gecikme koymanız beklenmektedir. Programınız Unix tabanlı olarak Pthreads kütüphanesini kullanmalıdır. Pthreads kütühanesindeki hazır mutex, semafor ve monitor yapılarını kullanabilirsiniz.
