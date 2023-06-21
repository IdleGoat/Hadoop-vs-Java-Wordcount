[TOC]
# Kelompok 9 - SBD02 
- Albertus Timothy Gunawan (2106639472)
- Amrita Deviayu Tunjungbiru (2106636584)
- Bisma Alif Alghifari (2106731402)
- Rafie Amandio Fauzan (2106731232)
- Seno Pamungkas Rahman (2106731586)

# Pendahuluan
Metode counting (penghitungan) merupakan salah satu teknik yang digunakan dalam pemrosesan data menggunakan Apache Hadoop dan Java. Tujuan utama dari metode counting adalah menghitung frekuensi kemunculan suatu nilai atau kunci tertentu dalam dataset yang besar. Berikut ini adalah penjelasan mengenai metode counting dalam Hadoop dan Java : 
1. **Hadoop**

Metode counting bekerja dengan cara memproses data secara terdistribusi dan paralel di dalam sistem Hadoop. Pemrosesan dilakukan dengan membagi dataset menjadi bagian-bagian yang lebih kecil yang dapat diolah secara terpisah. Setiap bagian dataset diproses oleh satu atau lebih task (tugas) yang dijalankan di dalam cluster Hadoop.

Metode counting pada Hadoop memanfaatkan paradigma pemrograman MapReduce. Dalam fase "Map", data input dipisahkan menjadi pasangan kunci-nilai (key-value pairs) oleh fungsi pemetaan (mapper). Mapper kemudian mengeluarkan pasangan kunci-nilai baru berdasarkan data yang diproses. Dalam fase "Reduce", pasangan kunci-nilai yang dihasilkan oleh mapper digabungkan berdasarkan kunci yang sama oleh fungsi pengurutan dan pengelompokan (sort and shuffle). Reducer kemudian memproses pasangan kunci-nilai yang sama untuk menghasilkan output akhir.

2. **Java**

Metode counting dalam bahasa pemrograman Java adalah pendekatan untuk menghitung atau mengumpulkan informasi tertentu dari suatu koleksi data. Metode ini melibatkan penggunaan variabel khusus yang bertindak sebagai "penghitung" untuk menjaga catatan jumlah kemunculan suatu nilai atau objek dalam suatu struktur data.

Dalam metode counting, pertama-tama, kita mendefinisikan variabel-variabel penghitung yang sesuai dengan jenis data atau objek yang ingin dihitung. Kemudian, kita melalui setiap elemen dalam struktur data dan menginkrementasikan nilai variabel penghitung yang sesuai untuk setiap kemunculan elemen tersebut. Dengan cara ini, kita dapat mengumpulkan informasi tentang frekuensi atau jumlah kemunculan nilai atau objek tertentu dalam struktur data.

Metode counting ini sangat berguna dalam berbagai konteks, seperti pemrosesan string, analisis teks, pengolahan gambar, dan banyak lagi. Misalnya, dalam pengolahan teks, kita dapat menggunakan metode counting untuk menghitung jumlah kata unik dalam sebuah teks atau menghitung frekuensi kemunculan kata-kata tertentu. Dalam pengolahan gambar, metode counting dapat digunakan untuk menghitung frekuensi kemunculan warna tertentu dalam suatu gambar.

# Instalasi Hadoop menggunakan WSL (Windows Subsytem For Linux)

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

| Spesifikasi    | Deskripsi         |
| -------------- | ----------------- |
| Prosesor       | AMD Ryzen 7 5800H |
| RAM            | 16 GB DDR4        |
| Penyimpanan    | 1024 GB SSD       |
| Sistem Operasi | Windows 11        |


## Skenario Testing
| Skenario   | File Size (mb) | Metode          |
| ---------- | -------------- | --------------- |
| Skenario 1 | 1              | Java dan Hadoop |
| Skenario 2 | 10             | Java dan Hadoop |
| Skenario 3 | 100            | Java dan Hadoop |
| Skenario 4 | 250            | Java dan Hadoop |
| Skenario 5 | 500            | Java dan Hadoop |
| Skenario 6 | 1000           | Java dan Hadoop |


## Hasil Running Time 
| FIle Size (mb) | Java   | Hadoop | Hadoop (Uber) |
| -------------- | ------ | ------ | ------------- |
| 1              | 0.07 s | 14 s   | 6 s           |
| 10             | Row 2  | 17 s   | 7 s           |
| 100            | Row 3  | 16 s   | 17 s          |
| 250            | Row 4  | 33 s   | 31 s          |
| 500            | Row 5  | 46 s   | 46 s          |
| 1000           | Row 6  | 64 s   | Row 6         |



## Visualization



# Analisis


# Referensi
- [Instalasi WSL](https://learn.microsoft.com/en-us/windows/wsl/install)
- [Instalasi Hadoop](https://kontext.tech/article/978/install-hadoop-332-in-wsl-on-windows)