const int htapin = A0;//seting pin
const int trbpin = A1;//seting pin
const int reso_index = 10;//0.1 second each one
const int reso_time = 1000 / reso_index;

void setup(void){
    pinMode(htapin,INPUT);
    pinMode(trbpin,INPUT);
    Serial.begin(9600);
}

int hta,trb,i = 1;//source analog data;value i setted for printing ignore it
float shidu,wendu;//source value of humidity and tempreature by data transform
int mod_shidu;//modified humidity
int mod_wendu_tmp;
float mod_wendu;//modified tempreature
int arr_hta[reso_index],arr_trb[reso_index];//setted for average NOT nessary

void modified_hta(float shidu){// resolation 5%
    mod_shidu = (int)shidu;
    if(mod_shidu % 5 > 2){
        mod_shidu = mod_shidu + (5 - mod_shidu % 5);
    }else{
        mod_shidu = mod_shidu - mod_shidu % 5;
    }
}

void modified_trb(float wendu){// resolation 0.5 'C
    mod_wendu_tmp = (int)(wendu * 100);
    if(mod_wendu_tmp % 50 >= 25){
        mod_wendu_tmp = mod_wendu_tmp + (50 - mod_wendu_tmp % 50);
    }else{
        mod_wendu_tmp = mod_wendu_tmp - mod_wendu_tmp % 50;
    }
    mod_wendu = (float)mod_wendu_tmp / 100;
}

void loop(void){
    int lctrl;//setted for average
    for(lctrl = 0;lctrl < reso_index;lctrl++){
        arr_hta[lctrl] = analogRead(htapin);
        arr_trb[lctrl] = analogRead(trbpin);
        delay(reso_time);
    }
    for(lctrl = 0,hta = trb = 0;lctrl < reso_index;lctrl++){
        hta += arr_hta[lctrl];
        trb += arr_trb[lctrl];
    }
    hta = hta / reso_index;
    trb = trb / reso_index;
    //finish average
    shidu = hta * 100.0 / 663;//core transform
    wendu = trb * 100.0 / 663 - 20;//core transform
    modified_hta(shidu);
    modified_trb(wendu);
    //finish modifying print than
    if(i % 10 == 1){
        Serial.println("Humidity\tTemperature");
    }
    Serial.print(mod_shidu);
    Serial.print("%\t\t");
    Serial.print(mod_wendu,1);
    Serial.println(" \'C");
    i++;
}
