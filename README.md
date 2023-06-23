# Table of Contents


1. [Pendahuluan](#Pendahuluan)
2. [Instalasi Hadoop menggunakan WSL](#Instalasi-Hadoop-menggunakan-WSL)
   1. [Instalasi WSL](#Instalasi-WSL)
   2. [Instalasi Hadoop](#Instalasi-Hadoop)
3. [Eksperimen](#Eksperimen)
   1. [Device Specification](#Device-Specification)
   2. [Skenario Testing](#Skenario-Testing)
   3. [Hasil Running Time](#Hasil-Running-Time)
   4. [Visualization](#Visualization)
4. [Analisis](#Analisis)
5. [Referensi](#Referensi)

# Kelompok 9 - SBD02 
- Albertus Timothy Gunawan (2106639472)
- Amrita Deviayu Tunjungbiru (2106636584)
- Bisma Alif Alghifari (2106731402)
- Rafie Amandio Fauzan (2106731232)
- Seno Pamungkas Rahman (2106731586)

# Pendahuluan
Metode counting (penghitungan) merupakan salah satu teknik yang digunakan dalam pemrosesan data menggunakan Apache Hadoop dan Java. Tujuan utama dari metode counting adalah menghitung frekuensi kemunculan suatu nilai atau kunci tertentu dalam dataset yang besar. Berikut ini adalah penjelasan mengenai metode counting dalam Hadoop dan Java : 
## Wordcount pada Hadoop

Metode counting bekerja dengan cara memproses data secara terdistribusi dan paralel di dalam sistem Hadoop. Pemrosesan dilakukan dengan membagi dataset menjadi bagian-bagian yang lebih kecil yang dapat diolah secara terpisah. Setiap bagian dataset diproses oleh satu atau lebih task (tugas) yang dijalankan di dalam cluster Hadoop.

Metode counting pada Hadoop memanfaatkan paradigma pemrograman MapReduce. Dalam fase "Map", data input dipisahkan menjadi pasangan kunci-nilai (key-value pairs) oleh fungsi pemetaan (mapper). Mapper kemudian mengeluarkan pasangan kunci-nilai baru berdasarkan data yang diproses. Dalam fase "Reduce", pasangan kunci-nilai yang dihasilkan oleh mapper digabungkan berdasarkan kunci yang sama oleh fungsi pengurutan dan pengelompokan (sort and shuffle). Reducer kemudian memproses pasangan kunci-nilai yang sama untuk menghasilkan output akhir.

## Wordcount pada Java

Metode counting dalam bahasa pemrograman Java adalah pendekatan untuk menghitung atau mengumpulkan informasi tertentu dari suatu koleksi data. Metode ini melibatkan penggunaan variabel khusus yang bertindak sebagai "penghitung" untuk menjaga catatan jumlah kemunculan suatu nilai atau objek dalam suatu struktur data.

Dalam metode counting, pertama-tama, kita mendefinisikan variabel-variabel penghitung yang sesuai dengan jenis data atau objek yang ingin dihitung. Kemudian, kita melalui setiap elemen dalam struktur data dan menginkrementasikan nilai variabel penghitung yang sesuai untuk setiap kemunculan elemen tersebut. Dengan cara ini, kita dapat mengumpulkan informasi tentang frekuensi atau jumlah kemunculan nilai atau objek tertentu dalam struktur data.

Metode counting ini sangat berguna dalam berbagai konteks, seperti pemrosesan string, analisis teks, pengolahan gambar, dan banyak lagi. Misalnya, dalam pengolahan teks, kita dapat menggunakan metode counting untuk menghitung jumlah kata unik dalam sebuah teks atau menghitung frekuensi kemunculan kata-kata tertentu. Dalam pengolahan gambar, metode counting dapat digunakan untuk menghitung frekuensi kemunculan warna tertentu dalam suatu gambar.

## Perbedaan Metode Java dan Hadoop

**Distribusi Tugas**

Java tidak secara otomatis mendistribusikan tugas-tugasnya dalam menjalankan programnya kecuali memanfaatkan multiple-thread pada mesinnya.

Hadoop menggunakan model pemrograman MapReduce yang digunakan untuk memproses tugas secara terdistribusi. MapReduce ini memungkinkan pemrosesan paralel pada beberapa node dalam kluster Hadoopnya.

**Skalabilitas**

Java biasanya tidak memiliki tingkat skalabilitas yang tinggi seperti Hadoop karena hanya dijalankan pada satu mesin.  Ini berarti ketika menjalankan WordCount di Java, pemrosesan dilakukan pada satu mesin dengan sumber daya terbatas, termasuk CPU, memori, dan bandwidth jaringan yang terbatas.

Hadoop ini memiliki skalabilitas yang tinggi karena dapat dengan mudah dijalankan pada kluster yang terdiri dari banyak node sehingga dapat mengatasi pemrosesan data yang sangat besar. Hadoop ini menggunakan pendekatan terdistribusi dan penggunaan paralelisme agar dapat memproses volume data yang sangat besar dengan cepat.

**Ketergantungan**

Java ini tidak memiliki ketergantungan pada framework tertentu dan dapat diimplementasikan secara mandiri menggunakan bahasa pemrograman java.

Hadoop ini memiliki ketergantungan pada framework Hadoop dan memanfaatkan ekosistemnya seperti Hadoop Distributed File System (HDFS) untuk melakukan penyimpanan dan pemrosesan data terdistribusinya.

# Instalasi Hadoop menggunakan WSL

## Instalasi WSL

Pada percobaan ini kita akan menggunakan Ubuntu-20.04

1. Untuk Menginstall WSL pada windows lakukan command berikut 
```bash
wsl --install -d Ubuntu-20.04
```

![](https://hackmd.io/_uploads/rkNVFKlu3.jpg)

2. Setelah sudah terinstall pastikan Ubuntu sudah terinstall dengan command 
```bash!
wsl -l -v
```

![](https://hackmd.io/_uploads/By7F_9g_n.png)

3. Kemudian jalankan Ubuntu pada Windows

![](https://hackmd.io/_uploads/B1bYY9g_h.png)


## Instalasi Hadoop
Selanjutnya kita melakukan instalasi hadoop

Referensi : [Kontext](https://kontext.tech/article/978/install-hadoop-332-in-wsl-on-windows)

1. Download Library Hadoop
```bash
wget https://dlcdn.apache.org/hadoop/common/hadoop-3.3.2/hadoop-3.3.2.tar.gz
```
2. Unzip Library yang telah di download
```bash
mkdir ~/hadoop

tar -xvzf hadoop-3.3.2.tar.gz -C ~/hadoop

cd ~/hadoop/hadoop-3.3.2/
```

3. Edit **etc/hadoop/hadoop-env.sh**
```bash
sudo nano etc/hadoop/hadoop-env.sh
```

Tambahkan environment variable JAVA_HOME

```
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
```
4. Edit etc/hadoop/core-site.xml
```bash
sudo nano etc/hadoop/core-site.xml
```

Tambahkan Konfigurasi dibawah ini
```
configuration>
     <property>
         <name>fs.defaultFS</name>
         <value>hdfs://localhost:9000</value>
     </property>
</configuration>
```
5. Edit etc/hadoop/hdfs-site.xml
```bash
sudo nano etc/hadoop/hdfs-site.xml
```
Tambahkan Konfigurasi dibawah ini
```
<configuration>
     <property>
         <name>dfs.replication</name>
         <value>1</value>
     </property>
     <property>
         <name>dfs.namenode.name.dir</name>
         <value>/home/**Nama Anda**/hadoop/dfs/name332</value>
     </property>
     <property>
         <name>dfs.datanode.data.dir</name>
         <value>/home/**Nama Anda**/hadoop/dfs/data332</value>
     </property>
</configuration>
```

selanjutnya buat dua folder baru
```
mkdir -p ~/hadoop/dfs/name332
mkdir -p ~/hadoop/dfs/data332
```

6. Edit file etc/hadoop/mapred-site.xml
```bash
sudo nano etc/hadoop/mapred-site.xml
```
Tambahkan Konfigurasi dibawah ini
```
<configuration>
     <property>
         <name>mapreduce.framework.name</name>
         <value>yarn</value>
     </property>
     <property>
         <name>mapreduce.application.classpath</name>
         <value>$HADOOP_MAPRED_HOME/share/hadoop/mapreduce/*:$HADOOP_MAPRED_HOME/share/hadoop/mapreduce/lib/*</value>
     </property>
</configuration>
```
7. Edit file etc/hadoop/yarn-site.xml
```bash
sudo nano etc/hadoop/yarn-site.xml
```
Tambahkan Konfigurasi dibawah ini
```
<configuration>
    <property>
        <name>yarn.nodemanager.aux-services</name>
        <value>mapreduce_shuffle</value>
    </property>
    <property>
        <name>yarn.nodemanager.env-whitelist</name>
        <value>JAVA_HOME,HADOOP_COMMON_HOME,HADOOP_HDFS_HOME,HADOOP_CONF_DIR,CLASSPATH_PREPEND_DISTCACHE,HADOOP_YARN_HOME,HADOOP_MAPRED_HOME</value>
    </property>
</configuration>
```
Selanjutnya lakukan command berikut untuk memformat namenode
```
bin/hdfs namenode -format
```


## Cara Menjalankan Hadoop
Gunakan Command dibawah ini untuk memulai program hadoop
```
sbin/start-dfs.sh
sbin/start-yarn.sh
```

apabila sudah dirun maka YARN web portal dapat dilihat di

http://localhost:8088/cluster


# Eksperimen
## Device Specification

| Spesifikasi    | Deskripsi                          |
|----------------|------------------------------------|
| Prosesor       | AMD Ryzen 7 5800H               |
| RAM            | 16 GB DDR4                         |
| Penyimpanan    | 1024 GB SSD                         |
| Sistem Operasi | Windows 11                         |


## Skenario Testing
| Skenario  | File Size (mb) | Metode |
|----------|----------|----------|
| Skenario 1   | 1    | Java dan Hadoop    | 
| Skenario 2    | 10    | Java dan Hadoop    | 
| Skenario 3    | 100    | Java dan Hadoop    | 
| Skenario 4    | 250    | Java dan Hadoop    | 
| Skenario 5    | 500    | Java dan Hadoop    | 


Kode yang digunakan pada testing kali ini adalah kode wordcount bawaan dari Hadoop yaitu hadoop-mapreduce-examples-3.3.2 yang terlampir pada folder github.

Untuk kode java yang digunakan ada pada folder Java_Wordcount

## Hasil Running Time 
| FIle Size (mb) | Java | Hadoop | Hadoop (Uber) |
|----------|----------|----------|----------|
| 1   | 0.07 s    | 14 s   | 6 s    |
| 10    | 0.552 s   | 17 s    | 7 s    |
| 100    | 6.65 s   | 16 s   | 17 s    |
| 250    | 23.83 s   | 33 s    | 31 s    |
| 500    | 32.253 s   | 46 s   | 46 s    |




## Visualization



# Analisis

Analisis hasil eksperimen di atas menunjukkan perbandingan waktu eksekusi menggunakan:
* Java TreeMap adalah struktur data yang efisien untuk menyimpan dan mengorganisir pasangan key-value, dengan kemampuan pencarian cepat dan pemeliharaan urutan objek.
* Hadoop MapReduce memiliki dua jenis implementasi: satu menggunakan konfigurasi satu node untuk menghindari overhead komunikasi antar komponen, namun kurang memanfaatkan paralelisme dan lokalitas data; yang lainnya menjalankan proses MapReduce dalam mode "uber" di satu mesin untuk mengurangi overhead pengaturan cluster.


Dapat terlihat bahwa pada ukuran file yang relatif kecil (1MB dan 10MB), implementasi menggunakan Java memiliki waktu eksekusi yang lebih cepat dibandingkan dengan Hadoop dan Hadoop (Uber). Namun, saat ukuran file semakin meningkat, terlihat bahwa implementasi menggunakan Hadoop (baik dengan atau tanpa mode "uber") memiliki waktu eksekusi yang lebih cepat dibandingkan dengan Java. Pada ukuran file 100MB, implementasi menggunakan Hadoop memiliki waktu eksekusi yang sedikit lebih cepat dibandingkan dengan Hadoop (Uber). Namun, pada ukuran file yang lebih besar (250MB, 500MB, dan 1000MB), implementasi menggunakan Hadoop dan Hadoop (Uber) memiliki waktu eksekusi yang relatif serupa.


# Kesimpulan

Berdasarkan eksperimen dan analisis yang dilakukan, dapat disimpulkan bahwa terdapat dua pendekatan yang dapat digunakan untuk memproses data, yaitu Java TreeMap dan Hadoop MapReduce
* Java TreeMap lebih cocok digunakan untuk masalah dengan dataset kecil dan masalah dapat dipecahkan secara efektif pada satu mesin, karena mengurutkan dan menyimpan pasangan key-value secara efisien dengan kompleksitas waktu O(log n).
* Hadoop MapReduce lebih cocok digunakan untuk pemrosesan terdistribusi dalam skala besar, karena dapat memanfaatkan pemrosesan secara paralel. Namun, Hadoop MapReduce menghasilkan overhead tambahan dalam pengaturan dan manajemen cluster. Pada konfigurasi satu node yang digunakan dalam eksperimen ini, keuntungan paralelisme dan lokalitas data tidak sepenuhnya dimanfaatkan

Oleh karena itu, penting untuk mempertimbangkan persyaratan spesifik dari permasalahan yang dihadapi untuk menentukan pendekatan yang tepat.

# Referensi
- [Instalasi WSL](https://learn.microsoft.com/en-us/windows/wsl/install)
- [Instalasi Hadoop](https://kontext.tech/article/978/install-hadoop-332-in-wsl-on-windows)
