
#define DBVERSION   20200111
#define PKT0B   0
#define PKT0E   8
#define PKT1B   9
#define PKT1E   28
#define PKT2B   29
#define PKT2E   64
#define PKT3B   65
#define PKT3E   124
#define PKT4B   125
#define PKT4E   142
#define PKT0LEN     6
#define PKT1LEN     19
#define PKT2LEN     42
#define PKT3LEN     91
#define PKTLEN  91

u32 training=0x55555555;

u8 sync=0x33;
u8 len=0;
u8 address=0;
u8 seq=0;
u8 key=0xf0;
u8 value=0x33;
u16 checksum=0;

u16 _free_=999;
u16 ixp=999;
u16 ixn=999;
u16 iyp=999;
u16 iyn=999;
u16 izp=999;
u16 izn=999;
u16 vbat=999;
u16 vbus=999;
u16 vcpu=999;
u16 vmpt=999;
u16 pwrdet=999;
u16 dac=999;

u16 ttx=999;
u16 trx=999;
u16 tba=999;
u16 txp=999;
u16 txn=999;
u16 typ=999;
u16 tyn=999;
u16 tzp=999;
u16 tzn=999;
u16 mptx=999;
u16 mpty=999;
u16 mptz=999;
u16 mptxyz=999;
u32 sclock=999;
u16 nrun=999;
u8 checksume2p=99;
u16 uptime=0;
u16 nmotor=999;
u8 alarmas=99;
u16 orb_period=999;
u8 bate=99;
u8 mote=99;
u8 ee1=99;
u8 lastreset=99;
u8 strfwd1=99;
u8 strfwd2=99;
u8 strfwd3=99;
u8 strfwd4=99;

u16 pktn=0;

u16 alfax=999;
u16 alfay=999;
u16 alfaz=999;
u16 ix=999;
u16 iy=999;
u16 iz=999;
u16 isolar=999;
u16 ibatp=999;
u16 ibatn=999;
u16 ibus=999;
u16 psolar=999;
u16 pbatp=999;
u16 pbus=999;

struct _tlm tlm[]=
{

	{   &training   ,   32  ,   32  ,   0   },
	{   &training   ,   32  ,   32  ,   0   },
	{   &sync   ,   8   ,   8   ,   0   },
	{   &len    ,   2   ,   2   ,   0   },
	{   &address    ,   4   ,   4   ,   0   },
	{   &seq    ,   2   ,   2   ,   0   },
	{   &key    ,   8   ,   8   ,   DATA    },
	{   &value  ,   8   ,   8   ,   DATA    },
	{   &checksum   ,   16  ,   16  ,   0   },

	{   &training   ,   32  ,   32  ,   0   },
	{   &training   ,   32  ,   32  ,   0   },
	{   &sync   ,   8   ,   8   ,   0   },
	{   &len    ,   2   ,   2   ,   0   },
	{   &address    ,   4   ,   4   ,   0   },
	{   &seq    ,   2   ,   2   ,   0   },
	{   &_free_ ,   5   ,   5   ,   0   },
	{   &ixp    ,   10  ,   10  ,   DATA    },
	{   &ixn    ,   10  ,   10  ,   DATA    },
	{   &iyp    ,   10  ,   10  ,   DATA    },
	{   &iyn    ,   10  ,   10  ,   DATA    },
	{   &izp    ,   10  ,   10  ,   DATA    },
	{   &izn    ,   10  ,   10  ,   DATA    },
	{   &vbat   ,   10  ,   10  ,   DATA    },
	{   &vbus   ,   10  ,   10  ,   DATA    },
	{   &vcpu   ,   10  ,   10  ,   DATA    },
	{   &vmpt   ,   10  ,   10  ,   DATA    },
	{   &pwrdet ,   10  ,   10  ,   DATA    },
	{   &dac    ,   5   ,   5   ,   DATA    },
	{   &checksum   ,   16  ,   16  ,   0   },

	{   &training   ,   32  ,   32  ,   0   },
	{   &training   ,   32  ,   32  ,   0   },
	{   &sync   ,   8   ,   8   ,   0   },
	{   &len    ,   2   ,   2   ,   0   },
	{   &address    ,   4   ,   4   ,   0   },
	{   &seq    ,   2   ,   2   ,   0   },
	{   &_free_ ,   2   ,   2   ,   0   },
	{   &ttx    ,   10  ,   10  ,   DATA    },
	{   &trx    ,   10  ,   10  ,   DATA    },
	{   &tba    ,   10  ,   10  ,   DATA    },
	{   &txp    ,   10  ,   10  ,   DATA    },
	{   &txn    ,   10  ,   10  ,   DATA    },
	{   &typ    ,   10  ,   10  ,   DATA    },
	{   &tyn    ,   10  ,   10  ,   DATA    },
	{   &tzp    ,   10  ,   10  ,   DATA    },
	{   &tzn    ,   10  ,   10  ,   DATA    },
	{   &mptx   ,   16  ,   16  ,   DATA    },
	{   &mpty   ,   16  ,   16  ,   DATA    },
	{   &mptz   ,   16  ,   16  ,   DATA    },
	{   &mptxyz ,   16  ,   16  ,   DATA    },
	{   &sclock ,   24  ,   24  ,   DATA    },
	{   &nrun   ,   16  ,   16  ,   DATA    },
	{   &checksume2p    ,   8   ,   8   ,   DATA    },
	{   &uptime ,   16  ,   16  ,   DATA    },
	{   &nmotor ,   12  ,   12  ,   DATA    },
	{   &alarmas    ,   8   ,   8   ,   DATA    },
	{   &orb_period ,   16  ,   16  ,   DATA    },
	{   &bate   ,   4   ,   4   ,   DATA    },
	{   &mote   ,   4   ,   4   ,   DATA    },
	{   &ee1    ,   4   ,   4   ,   DATA    },
	{   &lastreset  ,   4   ,   4   ,   DATA    },
	{   &strfwd1    ,   8   ,   8   ,   DATA    },
	{   &strfwd2    ,   8   ,   8   ,   DATA    },
	{   &strfwd3    ,   8   ,   8   ,   DATA    },
	{   &strfwd4    ,   8   ,   8   ,   DATA    },
	{   &checksum   ,   16  ,   16  ,   0   },

	{   &training   ,   32  ,   32  ,   0   },
	{   &training   ,   32  ,   32  ,   0   },
	{   &sync   ,   8   ,   8   ,   0   },
	{   &len    ,   2   ,   2   ,   0   },
	{   &address    ,   4   ,   4   ,   0   },
	{   &seq    ,   2   ,   2   ,   0   },
	{   &_free_ ,   4   ,   4   ,   0   },
	{   &stats[0].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[1].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[2].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[3].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[4].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[5].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[6].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[7].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[8].pp    ,   8   ,   32  ,   DATA    },
	{   &stats[0].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[1].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[2].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[3].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[4].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[5].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[6].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[7].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[8].pn    ,   8   ,   32  ,   DATA    },
	{   &stats[9].pp    ,   16  ,   32  ,   DATA    },
	{   &stats[10].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[11].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[12].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[13].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[14].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[9].ac    ,   20  ,   32  ,   DATA    },
	{   &stats[10].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[11].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[12].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[13].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[14].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[15].pp   ,   10  ,   32  ,   DATA    },
	{   &stats[16].pp   ,   10  ,   32  ,   DATA    },
	{   &stats[17].pp   ,   10  ,   32  ,   DATA    },
	{   &stats[18].pp   ,   10  ,   32  ,   DATA    },
	{   &stats[15].pn   ,   10  ,   32  ,   DATA    },
	{   &stats[16].pn   ,   10  ,   32  ,   DATA    },
	{   &stats[17].pn   ,   10  ,   32  ,   DATA    },
	{   &stats[18].pn   ,   10  ,   32  ,   DATA    },
	{   &stats[19].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[20].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[21].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[22].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[23].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[24].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[25].pp   ,   16  ,   32  ,   DATA    },
	{   &stats[19].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[20].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[21].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[22].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[23].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[24].ac   ,   20  ,   32  ,   DATA    },
	{   &stats[25].ac   ,   20  ,   32  ,   DATA    },
	{   &checksum   ,   16  ,   16  ,   0   },

	{   &pktn   ,   16  ,   16  ,   DATA    },
	{   &pktm[0]    ,   16  ,   16  ,   DATA    },
	{   &pktm[1]    ,   16  ,   16  ,   DATA    },
	{   &pktm[2]    ,   16  ,   16  ,   DATA    },
	{   &pktm[3]    ,   16  ,   16  ,   DATA    },
	{   &alfax  ,   16  ,   16  ,   DATA    },
	{   &alfay  ,   16  ,   16  ,   DATA    },
	{   &alfaz  ,   16  ,   16  ,   DATA    },
	{   &ix ,   16  ,   16  ,   DATA    },
	{   &iy ,   16  ,   16  ,   DATA    },
	{   &iz ,   16  ,   16  ,   DATA    },
	{   &isolar ,   16  ,   16  ,   DATA    },
	{   &ibatp  ,   16  ,   16  ,   DATA    },
	{   &ibatn  ,   16  ,   16  ,   DATA    },
	{   &ibus   ,   16  ,   16  ,   DATA    },
	{   &psolar ,   16  ,   16  ,   DATA    },
	{   &pbatp  ,   16  ,   16  ,   DATA    },
	{   &pbus   ,   16  ,   16  ,   DATA    }
};

//quitar tabs" por "
//quitar "tabs por "

//quitar &tab por &
//quitar 0 por 0

struct _tlm2 tlm2[]=
{

	{       0   ,"training","--","cabecera de entrenamiento 0x55555555"},
	{       0   ,"training","","cabecera de entrenamiento 0x55555555"},
	{       0   ,"sync","","sincronizacion 11001100 0x33"},
	{       0   ,"len","","longitud/tipo paquete"},
	{       0   ,"address","","direccion"},
	{       0   ,"seq","","numero de secuencia"},
	{       0   ,"key","","clave"},
	{       0   ,"value","","valor"},
	{       0   ,"checksum","","checksum"},

	{       0   ,"training","--","cabecera de entrenamiento 0x55555555"},
	{       0   ,"training","--","cabecera de entrenamiento 0x55555555"},
	{       0   ,"sync","--","sincronizacion 11001100 0x33"},
	{       0   ,"len","--","longitud/tipo paquete"},
	{       0   ,"address","--","direccion originatario"},
	{       0   ,"seq","--","numero de secuencia"},
	{       0   ,"_free_","--","sin asignar tq tamanyo paquete multiplo 8"},
	{   &adc[12]    ,"ixp","uA","intensidad panel XP"},
	{   &adc[10]    ,"ixn","uA","intensidad panel XN"},
	{   &adc[8] ,"iyp","uA","intensidad panel YP"},
	{   &adc[9] ,"iyn","uA","intensidad panel YN"},
	{   &adc[11]    ,"izp","uA","intensidad panel ZP"},
	{   &adc[13]    ,"izn","uA","intensidad panel ZN"},
	{   &adc[0] ,"vbat","mV","tension en bateria"},
	{   &adc[1] ,"vbus","mV","tension en BUS"},
	{   &adc[31]    ,"vcpu","mV","tension en CPU"},
	{   &adc[3] ,"vmpt","0","estados MPPT (dac 3bits)"},
	{   &adc[6] ,"pwrdet","dBm","detector de potencia, valor instantaneo   LIBRE"},
	{       0   ,"dac","div","tension hacia el control de ganancia      LIBRE"},
	{       0   ,"checksum","--","checksum"},

	{       0   ,"training","--","cabecera de entrenamiento 0x55555555"},
	{       0   ,"training","--","cabecera de entrenamiento 0x55555555"},
	{       0   ,"sync","--","sincronizacion 11001100 0x33"},
	{       0   ,"len","--","longitud/tipo paquete"},
	{       0   ,"address","--","direccion originatario"},
	{       0   ,"seq","--","numero de secuencia"},
	{       0   ,"_free_","--","sin asignar tq tamanyo paquete multiplo 8"},
	{   &adc[24]    ,"ttx","oC","temperatura transmisor"},
	{   &adc[19]    ,"trx","oC","temperatura receptor"},
	{   &adc[23]    ,"tba","oC","temperatura bateria"},
	{   &adc[16]    ,"txp","oC","temperatura panel XP"},
	{   &adc[17]    ,"txn","oC","temperatura panel XN"},
	{   &adc[18]    ,"typ","oC","temperatura panel YP"},
	{   &adc[27]    ,"tyn","oC","temperatura panel YN"},
	{   &adc[26]    ,"tzp","oC","temperatura panel ZP"},
	{   &adc[25]    ,"tzn","oC","temperatura panel ZN"},
	{       0   ,"mptx","s","contador actividad MPPT X metodo1"},
	{       0   ,"mpty","s","contador actividad MPPT Y metodo1"},
	{       0   ,"mptz","s","contador actividad MPPT Z metodo1"},
	{       0   ,"mptxyz","s","contador actividad MPPT XYZ metodo1"},
	{       0   ,"sclock","s","tiempo local satelite     (persistente)"},
	{       0   ,"nrun","--","contador arranques CPU    (persistente)"},
	{       0   ,"checksume2p","HEX","checksum E2PROM"},
	{       0   ,"uptime","min","tiempo desde el encendido"},
	{       0   ,"nmotor","--","contador encendidos motor (persistente)"},
	{       0   ,"alarmas","HEX","flags de error en [SOL 6 5 4 3 E2P RAM ROM]"},
	{       0   ,"orb_period","s","periodo orbita para calculo altura/drag"},
	{       0   ,"bate","HEX","maquina estados bateria"},
	{       0   ,"mote","HEX","maquina estador motor                   LIBRE"},
	{       0   ,"ee1","HEX","estado_sistema 1=carga inhabilitada durante 30s"},
	{       0   ,"lastreset","HEX","lastreset WD,PD,POR,BOR"},
	{       0   ,"strfwd1","HEX","byte para storeforward       (persistente)"},
	{       0   ,"strfwd2","HEX","byte para storeforward       (persistente)"},
	{       0   ,"strfwd3","HEX","byte para storeforward       (persistente)"},
	{       0   ,"strfwd4","HEX","byte para storeforward       (persistente)"},
	{       0   ,"checksum","--","checksum"},

	{       0   ,"training","--","cabecera de entrenamiento 0x55555555"},
	{       0   ,"training","--","cabecera de entrenamiento 0x55555555"},
	{       0   ,"sync","--","sincronizacion 11001100 0x33"},
	{       0   ,"len","--","longitud/tipo paquete"},
	{       0   ,"address","--","direccion originatario"},
	{       0   ,"seq","--","numero de secuencia"},
	{       0   ,"_free_","--","sin asignar tq tamanyo paquete multiplo 8"},
	{       0   ,"stats[0].pp","oC","ttx_pk+      TEMPERATURAS MAXIMAS"},
	{       0   ,"stats[1].pp","oC","trx_pk+"},
	{       0   ,"stats[2].pp","oC","tba_pk+"},
	{       0   ,"stats[3].pp","oC","txp_pk+"},
	{       0   ,"stats[4].pp","oC","txn_pk+"},
	{       0   ,"stats[5].pp","oC","typ_pk+"},
	{       0   ,"stats[6].pp","oC","tyn_pk+"},
	{       0   ,"stats[7].pp","oC","tzp_pk+"},
	{       0   ,"stats[8].pp","oC","tzn_pk+"},
	{       0   ,"stats[0].pn","oC","ttx_pk-      TEMPERATURAS MINIMAS"},
	{       0   ,"stats[1].pn","oC","trx_pk-"},
	{       0   ,"stats[2].pn","oC","tba_pk-"},
	{       0   ,"stats[3].pn","oC","txp_pk-"},
	{       0   ,"stats[4].pn","oC","txn_pk-"},
	{       0   ,"stats[5].pn","oC","typ_pk-"},
	{       0   ,"stats[6].pn","oC","tyn_pk-"},
	{       0   ,"stats[7].pn","oC","tzp_pk-"},
	{       0   ,"stats[8].pn","oC","tzn_pk-"},
	{       0   ,"stats[9].pp","uA","ixp_pk+       intensidades panel MAXIMA"},
	{       0   ,"stats[10].pp","uA","ixn_pk+"},
	{       0   ,"stats[11].pp","uA","iyp_pk+"},
	{       0   ,"stats[12].pp","uA","iyn_pk+"},
	{       0   ,"stats[13].pp","uA","izp_pk+"},
	{       0   ,"stats[14].pp","uA","izn_pk+"},
	{       0   ,"stats[9].ac","uA*t","carga generada por paneles XP   ixp_acc"},
	{       0   ,"stats[10].ac","uA*t","carga generada por paneles XN   ixn_acc"},
	{       0   ,"stats[11].ac","uA*t","carga generada por paneles YP   iyp_acc"},
	{       0   ,"stats[12].ac","uA*t","carga generada por paneles YN   iyn_acc"},
	{       0   ,"stats[13].ac","uA*t","carga generada por paneles ZP   izp_acc"},
	{       0   ,"stats[14].ac","uA*t","carga generada por paneles ZN   izn_acc"},
	{   &adcpp[0]   ,"stats[15].pp","mV","vbus_pk+     TENSIONES MAXIMAS"},
	{   &adcpp[1]   ,"stats[16].pp","mV","vbat_pk+"},
	{   &adcpp[31]  ,"stats[17].pp","mV","vcpu_pk+                           LIBRE"},
	{       0   ,"stats[18].pp","mV","adc[3]_pk+ vmpt"},
	{   &adcpn[0]   ,"stats[15].pn","mV","vbus_pk-     TENSIONES MINIMAS"},
	{   &adcpn[1]   ,"stats[16].pn","mV","vbat_pk-"},
	{   &adcpn[31]  ,"stats[17].pn","mV","vcpu_pk-                           LIBRE"},
	{       0   ,"stats[18].pn","mV","adc[3]_pk- vmpt"},
	{       0   ,"stats[19].pp","uA","ix+          intensidades MAXIMAS"},
	{       0   ,"stats[20].pp","uA","iy+"},
	{       0   ,"stats[21].pp","uA","iz+"},
	{       0   ,"stats[22].pp","uA","isolar+"},
	{       0   ,"stats[23].pp","uA","ibus+"},
	{       0   ,"stats[24].pp","uA","ibatp+"},
	{       0   ,"stats[25].pp","uA","ibatn+"},
	{       0   ,"stats[19].ac","uA*t","carga generada por paneles X    ix_acc"},
	{       0   ,"stats[20].ac","uA*t","carga generada por paneles Y    iy_acc"},
	{       0   ,"stats[21].ac","uA*t","carga generada por paneles Z    iz_acc"},
	{       0   ,"stats[22].ac","uA*t","carga generada desde paneles    isolar_acc"},
	{       0   ,"stats[23].ac","uA*t","carga entregada al bus          ibus_acc"},
	{       0   ,"stats[24].ac","uA*t","carga entregada por la bateria  ibatp_acc"},
	{       0   ,"stats[25].ac","uA*t","carga entregada a la bateria    ibatn_acc"},
	{       0   ,"checksum","--","checksum"},

	{       0   ,"pktn","--","contador paquetes recibidos en GNDSTA"},
	{       0   ,"pktm[0]","--","contador paquetes recibidos tipo0"},
	{       0   ,"pktm[1]","--","contador paquetes recibidos tipo1"},
	{       0   ,"pktm[2]","--","contador paquetes recibidos tipo2"},
	{       0   ,"pktm[3]","--","contador paquetes recibidos tipo3"},
	{       0   ,"alfax","deg","angulo incidencia sol panel X"},
	{       0   ,"alfay","deg","angulo incidencia sol panel Y"},
	{       0   ,"alfaz","deg","angulo incidencia sol panel Z"},
	{       0   ,"ix","uA","intensidad instantanea entregada por el MPTX"},
	{       0   ,"iy","uA","intensidad instantanea entregada por el MPTY"},
	{       0   ,"iz","uA","intensidad instantanea entregada por el MPTZ"},
	{       0   ,"isolar","uA","intensidad instantanea entregada por los MPT"},
	{       0   ,"ibatp","uA","intensidad desde la bateria"},
	{       0   ,"ibatn","uA","intensidad hacia la bateria"},
	{       0   ,"ibus","uA","intensidad hacia la carga (impt+ibatp)"},
	{       0   ,"psolar","uW","potencia desde MPT"},
	{       0   ,"pbatp","uW","potencia desde bateria"},
	{       0   ,"pbus","uW","potencia hacia bus"}
};
