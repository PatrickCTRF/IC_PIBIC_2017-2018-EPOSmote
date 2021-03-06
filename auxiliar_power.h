#define pm_active 0
#define pm_sleep 1
#define pm_pm0 2
#define pm_pm1 3
#define pm_pm2 4
#define pm_pm3 5

//====Aqui embaixo são só definições que nao consegui importar============================

// Base address for memory-mapped System Control Space
enum {
    SCS_BASE        = 0xe000e000
};

// Base address for memory-mapped System Control Registers
enum {
    SSI0_BASE       = 0x40008000,
    SSI1_BASE       = 0x40009000,
    UART0_BASE      = 0x4000c000,
    UART1_BASE      = 0x4000d000,
    I2C_MASTER_BASE = 0x40020000,
    I2C_SLAVE_BASE  = 0x40028000,
    SCR_BASE        = 0x400d2000,
    FLASH_CTRL_BASE = 0x400d3000,
    IOC_BASE        = 0x400d4000,
};

// System Control Registers offsets
    enum {                              // Description                                          Type    Value after reset
        CLOCK_CTRL      = 0x00,
        CLOCK_STA       = 0x04,
        RCGCGPT         = 0x08,
        SCGCGPT         = 0x0C,
        DCGCGPT         = 0x10,
        SRGPT           = 0x14,
        RCGCSSI         = 0x18,
        SCGCSSI         = 0x1C,
        DCGCSSI         = 0x20,
        SRSSI           = 0x24,
        RCGCUART        = 0x28,
        SCGCUART        = 0x2C,
        DCGCUART        = 0x30,
        SRUART          = 0x34,
        RCGCI2C         = 0x38,
        SCGCI2C         = 0x3C,
        DCGCI2C         = 0x40,
        SRI2C           = 0x44,
        RCGCSEC         = 0x48,
        SCGCSEC         = 0x4C,
        DCGCSEC         = 0x50,
        SRSEC           = 0x54,
        PMCTL           = 0x58,
        SRCRC           = 0x5C,
        PWRDBG          = 0x74,
        CLD             = 0x80,
        IWE             = 0x94,
        I_MAP           = 0x98,
        RCGCRFC         = 0xA8,
        SCGCRFC         = 0xAC,
        DCGCRFC         = 0xB0,
        EMUOVR          = 0xB4
    };
    
    enum
    {
        SLEEPDEEP = 1 << 2,
    };
    
    // System Control Space offsets
    enum {                              // Description                                          Type    Value after reset
        MCR             = 0x000,        // Master Control Register                              -       0x00000000
        ICTR            = 0x004,        // Interrupt Controller Type Register                   RO      0x????????
        ACTLR           = 0x008,        // Auxiliary Control Register                           R/W     0x????????
        STCTRL          = 0x010,        // SysTick Control and Status Register                  R/W     0x00000000
        STRELOAD        = 0x014,        // SysTick Reload Value Register                        R/W     0x00000000
        STCURRENT       = 0x018,        // SysTick Current Value Register                       R/WC    0x00000000
        IRQ_ENABLE0     = 0x100,        // Interrupt  0-31 Set Enable                           R/W     0x00000000
        IRQ_ENABLE1     = 0x104,        // Interrupt 32-63 Set Enable                           R/W     0x00000000
        IRQ_ENABLE2     = 0x108,        // Interrupt 64-95 Set Enable                           R/W     0x00000000
        IRQ_DISABLE0    = 0x180,        // Interrupt  0-31 Clear Enable                         R/W     0x00000000
        IRQ_DISABLE1    = 0x184,        // Interrupt 32-63 Clear Enable                         R/W     0x00000000
        IRQ_DISABLE2    = 0x188,        // Interrupt 64-95 Clear Enable                         R/W     0x00000000
        IRQ_PEND0       = 0x200,        // Interrupt  0-31 Set Pending                          R/W     0x00000000
        IRQ_PEND1       = 0x204,        // Interrupt 32-63 Set Pending                          R/W     0x00000000
        IRQ_PEND2       = 0x208,        // Interrupt 64-95 Set Pending                          R/W     0x00000000
        IRQ_UNPEND0     = 0x280,        // Interrupt  0-31 Clear Pending                        R/W     0x00000000
        IRQ_UNPEND1     = 0x284,        // Interrupt 32-63 Clear Pending                        R/W     0x00000000
        IRQ_UNPEND2     = 0x288,        // Interrupt 64-95 Clear Pending                        R/W     0x00000000
        IRQ_ACTIVE0     = 0x300,        // Interrupt  0-31 Active Bit                           R/W     0x00000000
        IRQ_ACTIVE1     = 0x304,        // Interrupt 32-63 Active Bit                           R/W     0x00000000
        IRQ_ACTIVE2     = 0x308,        // Interrupt 64-95 Active Bit                           R/W     0x00000000
        CPUID           = 0xd00,        // CPUID Base Register                                  RO      0x410fc231
        INTCTRL         = 0xd04,        // Interrupt Control and State Register                 R/W     0x00000000
        VTOR            = 0xd08,        // Vector Table Offset Register                         R/W     0x00000000
        AIRCR           = 0xd0c,        // Application Interrupt/Reset Control Register         R/W
        SCR             = 0xd10,        // System Control Register                              R/W     0x00000000
        CCR             = 0xd14,        // Configuration Control Register                       R/W     0x00000000
        SHPR1           = 0xd18,        // System Handlers 4-7 Priority                         R/W     0x00000000
        SHPR2           = 0xd1c,        // System Handlers 8-11 Priority                        R/W     0x00000000
        SHPR3           = 0xd20,        // System Handlers 12-15 Priority                       R/W     0x00000000
        SHCSR           = 0xd24,        // System Handler Control and State Register            R/W     0x00000000
        CFSR            = 0xd28,        // Configurable Fault Status Register                   R/W     0x00000000
        HFSR            = 0xd2c,        // Hard Fault Status Register
        SWTRIG          = 0xf00         // Software Trigger Interrupt Register                  WO      0x00000000
    };


typedef unsigned long Reg32;

volatile Reg32 & scs(unsigned int o) { return reinterpret_cast<volatile Reg32 *>(SCS_BASE)[o / sizeof(Reg32)]; }
volatile Reg32 & scr(unsigned int o) { return reinterpret_cast<volatile Reg32 *>(SCR_BASE)[o / sizeof(Reg32)]; }


//Começa o emote3_tsc.h

static const unsigned int CLOCK = 32000;
typedef int Time_Stamp;
typedef int Hertz;

enum
{
    TSC_BASE = 0x400D5000
};

enum Offset
{
    //Register Name      Offset  Type  Width  Reset Value 
    SMWDTHROSC_ST0    =  0x40, //RW    32     0x00000000 
    SMWDTHROSC_ST1    =  0x44, //RW    32     0x00000000 
    SMWDTHROSC_ST2    =  0x48, //RW    32     0x00000000 
    SMWDTHROSC_ST3    =  0x4C, //RW    32     0x00000000 
    SMWDTHROSC_STLOAD =  0x50, //RO    32     0x00000001 
    SMWDTHROSC_STCC   =  0x54, //RW    32     0x00000038 
    SMWDTHROSC_STCS   =  0x58, //RW    32     0x00000000 
    SMWDTHROSC_STCV0  =  0x5C, //RO    32     0x00000000 
    SMWDTHROSC_STCV1  =  0x60, //RO    32     0x00000000 
    SMWDTHROSC_STCV2  =  0x64, //RO    32     0x00000000 
    SMWDTHROSC_STCV3  =  0x68, //RO    32     0x00000000 
};


volatile Reg32 & reg(unsigned int o) { return reinterpret_cast<volatile Reg32 *>(TSC_BASE)[o / sizeof(Reg32)]; }

Hertz frequency() { return CLOCK; }

//void wake_up_at(Time_Stamp t, const Interrupt_Handler & handler);

Time_Stamp us_to_ts(const Time_Stamp & us)
{
    return (us / 1000) * (frequency() / 1000);
}

Time_Stamp time_stamp()
{
    Time_Stamp ret = 0;
    // Ensuring read order. The time read from ST1-3 is latched at the moment ST0 is read
    ret += reg(SMWDTHROSC_ST0);
    ret += reg(SMWDTHROSC_ST1) << 8;
    ret += reg(SMWDTHROSC_ST2) << 16;
    ret += reg(SMWDTHROSC_ST3) << 24;
    
    return ret; //+ _offset;
}

//Termina o emote3_tsc




//=================Acabam aqui as definiçoes, abaixo são minhas funções===================





/**
 * Esta função aguarda por um tempo requisitado de delay, sendo este cronometrado 
 * diretamente pelo contador do sleep timer do sistema e trabalhando com o conceito de Time Stamp.
 * Vale lembrar que Time_Stamp é apenas um tipo definido dentro do sistema e equivalente a um 
 * inteiro ou long (a verificar).
 */
void delayRealTimeus(int us){
	
	Time_Stamp time_stamp_inicial = time_stamp();
	
	Time_Stamp ts = us_to_ts(us);//Este é o tempo de delay desejado.
	
	//Nós apenas aguardaremos aqui até que o tempo atual seja igual ao tempo de espera desejado quando o delay foi chamado.
	while(time_stamp() < ts + time_stamp_inicial);
	
}




void setPowerMode(int mode){

	
	switch(mode){
	
		case pm_active:
			
			break;
		
		case pm_sleep:
			scs(SCR) &= ~SLEEPDEEP;
			
			scr(SCGCUART) |= (3);
			scr(SCGCRFC) |= (1);
			scr(SCGCSEC) |= (3);
			scr(SCGCI2C) |= (1);
			scr(SCGCSSI) |= (3);
			scr(SCGCGPT) |= (15);
			
			break;
			
		case pm_pm0:
			scs(SCR) |= SLEEPDEEP;
			scr(PMCTL) = 0;
			
			scr(DCGCUART) &= ~(3);
			scr(DCGCRFC) &= ~(1);
			scr(DCGCSEC) &= ~(3);
			scr(DCGCI2C) &= ~(1);
			scr(DCGCSSI) &= ~(3);
			scr(DCGCGPT) &= ~(15);
			
			
			break;
			
		case pm_pm1:
			scs(SCR) |= SLEEPDEEP;
			scr(PMCTL) = 1;
			break;
			
		case pm_pm2:
			scs(SCR) |= SLEEPDEEP;
			scr(PMCTL) = 2;
			break;
			
		case pm_pm3:
			scs(SCR) |= SLEEPDEEP;
			scr(PMCTL) = 3;
			break;
		
		default:
			break;
	}
	
	
	
	ASM("wfi");
	
}



void wake_up_after_us(int delay_us){//Entre com um valor de delay em microsegundos para o alarme.
	
	Time_Stamp ts = us_to_ts(delay_us);
	
    ts = ts + time_stamp();
    
    //Ensuring write order. Tem que escrever do ST3 para o ST0, pois a escrita neste último faz o "update" de tudo.
    reg(SMWDTHROSC_ST3) = ts >> 24;
	reg(SMWDTHROSC_ST2) = ts >> 16;
	reg(SMWDTHROSC_ST1) = ts >> 8;
	reg(SMWDTHROSC_ST0) = ts >> 0;
	
	scs(IRQ_ENABLE1) = 1 << 0;//Ativando a interrupção de sleep timer. Nao fez diferença e continua sem contar dps de acordar.
	
}













