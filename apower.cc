#include <adc.h>
#include <gpio.h>
#include <alarm.h>

#include <utility/ostream.h>
	

#include "auxiliar_power.h"
#include <periodic_thread.h>



static const unsigned int DUTY_CYCLE = 1; // %
//static const bool half_duty_cycle = true;

using namespace EPOS;

OStream cout;
volatile int recebeu;//variável que indica se acabamos de receber um dado e que é zerada logo após enviarmos a mensagem designada.
const unsigned int delay_time = 2000000;

bool led_value;
GPIO * led;


const int iterations = 100;
const long period_a = 100; // ms

void ultra_delay(){
	
	long i=0, j=0, numb = 316;
	
	while(i++<numb){
		
		while(j++<numb)cout << j << "\n"; j=0;
		
		
	}i=0;
	
}

void led_envio(){
	
	

	led = new GPIO('C',3, GPIO::OUT);

	led->set(1);//Sequencia para indicar dado sendo enviado.
	cout << "a";
    ultra_delay();
    led->set(0);
	cout << "b";
    ultra_delay();
    led->set(1);
	cout << "a";
    ultra_delay();
    led->set(0);
	cout << "b";
    ultra_delay();
    
    free(led);

    return;
}

void led_recebimento(){

	led->set(1);//Sequencia para indicar dado recebido.
    Alarm::delay(delay_time);
    led->set(0);
    Alarm::delay(delay_time);
    
}

void handler(const unsigned int & id){

    cout << "Okay!" << endl;
}

int func_a(){

    cout << "A";
    for(int i = 0; i < iterations; i++) {
	    led_envio();
        Periodic_Thread::wait_next();
        cout << "a";
    }
    cout << "A";
    return 'A';
}

int main()
{
	led_envio();
    cout << "Hello main" << endl;
    
	
    ADC level_adc = ADC{ADC::SINGLE_ENDED_ADC2};
	//auto level_adc = ADC{ADC::TEMPERATURE};
    
    while(1){
    	
    	//Periodic_Thread thread_a(RTConf(period_a * 1000, iterations), &func_a);
    	//int status_a = thread_a.join();
    	
    	led_envio();
		cout << "teste" << level_adc.read() << endl;
    	//wake_up_after_us(5000000);
    	//setPowerMode(pm_pm1);
    	
		
	}

    return 0;
}
