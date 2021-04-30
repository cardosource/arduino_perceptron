

bool iniciando;
int pino[4];
int x1[4]; 
int x2[4]; 
int  saida[4];
double sinapse = 0.5;
int ativo;
int resposta[4];


void setup() {
  
  x1[0] = 1;
  x1[1] = 1;
  x1[2] = 0;
  x1[3] = 0;
  
  x2[0] = 1;
  x2[1] = 0;
  x2[2] = 1;
  x2[3] = 0;
  
  resposta[0]=1;
  resposta[1]=0;
  resposta[2]=0;
  resposta[3]=0;
  
 
  pino[0]=13;
  pino[1]=12;
  pino[2]=11;
  pino[3]=10;


  Serial.begin(9600);  
      
iniciando = false;
}
    
void loop() {
 if (iniciando == false){
   
    for (byte e = 0; e < sizeof(x1)/sizeof(int); e++) {
     
      int soma = (x1[e] * sinapse) + (x2[e] * sinapse); 
     
       if(soma>= 1){
         ativo = 1;
         saida[e] = ativo;
           }      
       else if(soma<= 0){
         ativo =0;
         saida[e] = ativo;
       }      
  }
 
 
    for(int res = 0; res < sizeof(saida)/sizeof(int); res++){     
      delay(500);
      
      if (resposta[res] == saida[res]){
          // Serial.println(pino[res]);
           digitalWrite(pino[res], HIGH);
           delay(500);
           Serial.print("resposta correta : ");
           Serial.print(saida[res]);   
           Serial.print("\n");
           
      }else{
           Serial.print("resposta incorreta : ");
           Serial.print(saida[res]);
           Serial.print("\n"); 
           
      }
       
       
    }
    


for(int desligar = 0; desligar < sizeof(pino)/sizeof(int); desligar++){
     delay(500);
     Serial.println("desligando : "+String(pino[sizeof(pino)/sizeof(*pino)-desligar-1]));
     digitalWrite(pino[sizeof(pino)/sizeof(*pino)-desligar-1], LOW);  
       }
   }
   iniciando = true;
}

