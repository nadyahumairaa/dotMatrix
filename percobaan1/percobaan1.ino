#include <LedControlMS.h>
LedControl lc =LedControl(11,13,10);//urutannya>DIN,CLK,CS

//waktu tunggu yang dideklarasikan di variabel global
unsigned long waktutunggu = 50;

int col;
int row;
int address;

void setup() {
  // jumlah perangkat yang terah dirangkai antara arduino dengan dot matrix
  int devices=lc.getDeviceCount();
  //Inisialisasikan semua perangkat(didalam void loop)
  for(int address=0;address<devices;address++){
    //IC MAX72XX berada dalam mode sleppp saat straup
    lc.shutdown(address,false);
    //atur kecerahan ke tingkat menengah.
    lc.setIntensity(address,8);
    //kosongkan data di dotmatrix(clear display)
    lc.clearDisplay(address);
    }
}

void loop() {
  //baca jumlah perangkat
  int devices=lc.getDeviceCount();

  //perulangan pertama untuk pengisian data 1 persatu-satu
  for(row=00;row<8;row++){
    for(col=00;col<8;col++){
      for(address=00;address<devices;address++){
      lc.setLed(address,row,col,true); delay(waktutunggu);
      }  
  }
}
//perulangan pertama untuk pengosongan data 1 persatu
for(row=00;row<8;row++){
 for(col=00;col<8;col++){
  for(address=0;address<devices;address++){
  lc.setLed(address,row,col,false);delay(waktutunggu);
  } 
 }
  }
}
