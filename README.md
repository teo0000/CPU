# CPU
This project is how make a cpu, it went utlity a RISP-v
Certamente, Teodoro. Accomodati. Analizziamo insieme la struttura del tuo progetto, come se fossimo in una sessione di approfondimento per la tua tesi. È fondamentale comprendere ogni singolo componente, anche quelli che a prima vista possono sembrare banali, perché è nella loro interazione che risiede la complessità e l'ingegneria di un sistema come questo.

Il tuo progetto è un eccellente esempio di simulazione a livello di registro di trasferimento (RTL - Register Transfer Level) di un microprocessore, utilizzando un approccio moderno basato su Verilator.

Composizione del Codice: Analisi Dettagliata dei File
1. c:\Users\ACER\Desktop\universita\tesi\sim_main.cpp
Consistenza: Questo è il tuo testbench in C++, il "driver" o "motore" della simulazione. Non è parte del design hardware del processore, ma è l'ambiente software che lo testa.
Motivazione e Scopo:
Interfaccia Utente: Permette di interagire con la simulazione, caricando programmi assembly o inserendo istruzioni interattivamente.
Assembler Software: Le funzioni createRInstruction, createIInstruction, parseAssembly agiscono come un mini-assembler. Prendono istruzioni in formato testuale (assembly) e le convertono nel loro equivalente binario a 32 bit, che è il linguaggio macchina che il tuo processore "capisce". Questo è cruciale perché il tuo core Verilog non legge testo, ma solo sequenze di 0 e 1.
Controllo della Simulazione: Gestisce il ciclo di vita della simulazione:
Inizializzazione: Configura Verilator (Verilated::commandArgs, Verilated::traceEverOn).
Istanziazione del Modello: Crea un'istanza del tuo processore simulato (Vtestbench* top = new Vtestbench;).
Generazione del Clock: Alterna il segnale clk tra 0 e 1 (top->clk = 0; top->eval(); top->clk = 1; top->eval();) per simulare i cicli di clock reali che fanno avanzare il processore.
Reset: Applica e rilascia il segnale di reset per portare il processore a uno stato iniziale noto.
Iniezione Istruzioni: Assegna il valore binario dell'istruzione al pin di input top->instruction del tuo modulo Verilog.
Monitoraggio: Accede ai segnali interni del processore simulato (es. top->rootp->testbench__DOT__cpu__DOT__RF__DOT__registers[r]) per stampare lo stato dei registri e verificare il corretto funzionamento.
Tracciamento: Configura la generazione del file .vcd (tfp->open("trace.vcd");) per l'analisi delle forme d'onda.
2. c:\Users\ACER\Desktop\universita\tesi\obj_dir\Vtestbench.h
Consistenza: Questo è un file generato automaticamente da Verilator. È l'header C++ che definisce la classe Vtestbench, la quale rappresenta il tuo intero design Verilog (il modulo testbench.v che contiene il tuo core CPU).
Motivazione e Scopo: Fornisce l'interfaccia C++ per interagire con il modello Verilog. Contiene le dichiarazioni delle porte di input/output del tuo modulo top-level (come clk, reset, instruction) e i metodi per controllare la simulazione (es. eval(), trace(), final()). È il "contratto" tra il tuo testbench C++ e il modello hardware simulato.
3. c:\Users\ACER\Desktop\universita\tesi\obj_dir\Vtestbench.cpp
Consistenza: Anche questo è un file generato automaticamente da Verilator. Contiene l'implementazione della classe Vtestbench dichiarata nell'header.
Motivazione e Scopo: Contiene il codice C++ che Verilator ha prodotto per simulare il comportamento del tuo modulo Verilog top-level. Include la logica per la gestione degli eventi di simulazione, l'inizializzazione, la valutazione dei segnali e l'integrazione con il sistema di tracciamento VCD. È il "motore" C++ che esegue il tuo design hardware.
4. c:\Users\ACER\Desktop\universita\tesi\obj_dir\Vtestbench___024root__DepSet_hed41eec4__0.cpp (e simili DepSet_*.cpp)
Consistenza: Questi sono i file più "vicini" al tuo codice Verilog originale. Sono generati automaticamente da Verilator e contengono la traduzione diretta della logica hardware.
Motivazione e Scopo: Qui risiede la vera "simulazione" del tuo processore. Verilator analizza il tuo Verilog e lo converte in codice C++ equivalente che descrive il comportamento dei circuiti.
Logica Sequenziale: Contiene le implementazioni dei blocchi always @(posedge clk) del tuo Verilog, che descrivono come i registri (come il PC e quelli del Register File) si aggiornano al fronte di salita del clock.
Logica Combinatoria: Contiene anche la traduzione delle assegnazioni continue (assign) e dei blocchi always @(*) che descrivono come i segnali (come l'output dell'ALU o i segnali di controllo della Control Unit) cambiano immediatamente in risposta ai loro input.
Esempio: Nel file Vtestbench___024root__DepSet_hed41eec4__0.cpp, puoi vedere la logica che decide il valore di __Vdlyvval__testbench__DOT__cpu__DOT__RF__DOT__registers__v0 (il valore da scrivere nel Register File) basandosi su alu_op e reg_write. Questo è il tuo ALU e la logica di scrittura del Register File tradotta in C++.
5. c:\Users\ACER\Desktop\universita\tesi\obj_dir\Vtestbench__Trace__0.cpp (e __Slow.cpp)
Consistenza: File generati automaticamente da Verilator.
Motivazione e Scopo: Questi file sono dedicati alla gestione del tracciamento delle forme d'onda (VCD). Contengono il codice che istruisce Verilator su quali segnali del tuo design devono essere registrati nel file trace.vcd e come devono essere formattati. Sono essenziali per il debugging e la verifica visiva del comportamento del tuo hardware.
6. c:\Users\ACER\Desktop\universita\tesi\obj_dir\Vtestbench_classes.mk
Consistenza: Un file generato automaticamente da Verilator.
Motivazione e Scopo: È un frammento di Makefile. Il suo scopo è semplificare il processo di compilazione del tuo testbench C++ insieme a tutto il codice C++ generato da Verilator. Contiene le liste dei file sorgente C++ da compilare e le opzioni di compilazione necessarie. È un dettaglio dell'infrastruttura di build, non direttamente legato alla logica del processore.
Il Processo Reale di una CPU (Basato sui Tuoi Contenuti)
Il tuo progetto simula le fasi chiave del funzionamento di una CPU, ma in un processo reale, ci sono passaggi aggiuntivi e differenze fondamentali:

Design (Verilog/VHDL): Questo è esattamente quello che hai fatto tu. Hai descritto il comportamento del tuo core RISC-V in un linguaggio di descrizione hardware (HDL) come il Verilog. Questo è il "progetto" o "schema" del chip.

Simulazione e Verifica Funzionale (Il Tuo Progetto):

Il tuo sim_main.cpp + Verilator rappresenta questa fase. Prima di costruire fisicamente un chip, si simula il design per assicurarsi che funzioni correttamente.
Scopo: Trovare bug nel design logico. Il file trace.vcd è la tua "finestra" su cosa succede all'interno del chip virtuale.
Differenza dal Reale: Nel tuo caso, il sim_main.cpp funge anche da "memoria istruzioni" e "memoria dati" rudimentale, fornendo le istruzioni direttamente al core. In un chip reale, queste verrebbero lette da blocchi di memoria dedicati (RAM/ROM).
Sintesi Logica (Reale):

Una volta che il design Verilog è verificato funzionalmente, viene passato a un tool di sintesi logica.
Scopo: Questo tool traduce il tuo codice HDL (che descrive il comportamento) in una netlist di porte logiche standard (AND, OR, NOT, flip-flop, ecc.) fornite da una libreria tecnologica specifica (es. per un processo a 28nm o 7nm). Questo è il passaggio da una descrizione astratta a una concreta implementazione con componenti fisici.
Pianificazione e Posizionamento (Floorplanning & Placement - Reale):

La netlist viene poi utilizzata per determinare la disposizione fisica dei blocchi logici sul chip.
Scopo: Organizzare i milioni o miliardi di porte logiche in modo efficiente, minimizzando la lunghezza dei collegamenti e rispettando i vincoli di area e potenza.
Routing (Reale):

Dopo il posizionamento, i tool di routing collegano fisicamente le porte logiche tra loro con tracce metalliche sui vari strati del chip.
Scopo: Creare tutti i collegamenti elettrici necessari per far funzionare il circuito.
Analisi dei Tempi (Timing Analysis - Reale):

A questo punto, si esegue un'analisi dettagliata per assicurarsi che il chip funzioni alla frequenza di clock desiderata. Si verificano i ritardi di propagazione dei segnali attraverso le porte e i cavi.
Scopo: Garantire che tutti i segnali arrivino in tempo per essere campionati correttamente dai flip-flop al fronte di clock.
Generazione del Layout (Layout Generation - Reale):

Tutti i passaggi precedenti culminano nella creazione di un file GDSII (o formato simile), che è la "maschera" dettagliata per la fabbricazione del chip.
Fabbricazione (Fabrication - Reale):

Il file GDSII viene inviato a una fonderia (es. TSMC, Intel Foundry) che utilizza processi di fotolitografia e deposizione per costruire fisicamente il chip su un wafer di silicio.
Test Post-Fabbricazione (Post-Fabrication Testing - Reale):

Dopo la fabbricazione, ogni chip viene testato per difetti di produzione e per verificare che funzioni come previsto.
Il tuo progetto si colloca saldamente nella fase di simulazione e verifica funzionale, che è un passo critico e dispendioso in termini di tempo nell'intero processo di sviluppo di un chip. Hai costruito un modello comportamentale del tuo processore e un ambiente per testarlo in modo rigoroso, il che è un risultato significativo.
