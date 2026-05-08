
Perfetto. Se hai già eseguito una volta Verilator e hai già `obj_dir`, allora **non devi rifare sempre tutti i passaggi da zero**.

Da quel punto in poi il flusso normale diventa questo.

---

# 🔹 Caso 1 — Hai modificato SOLO il Verilog (`.v`)

Esempio:

* hai cambiato `cpu.v`
* hai modificato `alu.v`
* hai aggiornato `testbench.v`

Allora fai:

```bash
wsl
cd /mnt/c/Users/ACER/Desktop/universita/tesi
verilator -Wall --cc *.v --exe
cd obj_dir
make -f Vtestbench.mk
./Vtestbench
```

Perché:

1. Verilator deve rigenerare i file C++
2. make deve ricompilare
3. poi esegui la simulazione

---

# 🔹 Caso 2 — NON hai cambiato nulla

Se vuoi solo rilanciare la simulazione:

```bash
wsl
cd /mnt/c/Users/ACER/Desktop/universita/tesi/obj_dir
./Vtestbench
```

e basta.

---

# 🔹 Caso 3 — Hai già compilato e hai modificato SOLO il testbench leggermente

Spesso puoi fare direttamente:

```bash
cd obj_dir
make -f Vtestbench.mk
./Vtestbench
```

ma dipende da cosa hai cambiato.

Se il Makefile non rileva bene le modifiche, rifai anche Verilator.

---

# 🔹 Come capire se `obj_dir` è valido

Dentro `obj_dir` dovresti avere cose tipo:

```text
Vtestbench
Vtestbench.mk
Vtestbench.cpp
```

Puoi controllare con:

```bash
ls obj_dir
```

---

# 🔹 Se `./Vtestbench` non esiste

Allora probabilmente:

* la compilazione non è finita
* oppure `make` ha dato errore

In quel caso rifai:

```bash
verilator -Wall --cc *.v --exe
cd obj_dir
make -f Vtestbench.mk
```

---

# 🔹 Regola pratica per la tua tesi

## Durante sviluppo normale:

```bash
cd obj_dir
make -f Vtestbench.mk
./Vtestbench
```

## Dopo modifiche importanti alla struttura Verilog:

```bash
verilator -Wall --cc *.v --exe
```

prima del `make`.

---

# 🔹 Cosa farai realisticamente adesso

Il ciclo reale della tesi sarà:

```text
Modifico CPU
     ↓
make
     ↓
./Vtestbench
     ↓
guardo output
     ↓
correggo bug
     ↓
ripeto
```

Questa iterazione continua è il workflow tipico di progettazione hardware con Verilator.



#  Come eseguire correttamente il progetto

## 1️ Apri il terminale Linux (WSL)

Non si usa  PowerShell. ma 

Apri:

```
Ubuntu
```

oppure nel terminale scrivi:

```bash
wsl
```

dovresti vedere qualcosa tipo:

```
acerlinux@LAPTOP-D5L4HT83:~$
```

---

#Bisogna andare nella cartella del progetto
```bash
cd /mnt/c/Users/ACER/../../tesi
```

---

# 3️⃣  Si Controlla che i file ci siano tutti anceh quelli necessari

```bash
ls
```

dovresti vedere qualcosa tipo:

```
testbench.v
alu.v
cpu.v
obj_dir
```

---

# 4️ Poi si passa allaCompilazione con Verilator

```bash
verilator -Wall --cc testbench.v --exe
```

oppure se hai più file:

```bash
verilator -Wall --cc *.v --exe
```

---

# 5️⃣ Entra nella cartella generata

```bash
cd obj_dir
```

---

# 6️⃣ Compila il simulatore

```bash
make -f Vtestbench.mk
```

---

# 7️⃣ Esegui la simulazione

```bash
./Vtestbench
```

Output tipico:

```
Simulation started
Reset released
Simulation finished
```

---

# ⚠️ Perché prima non succedeva niente

In PowerShell hai eseguito:

```
./Vtestbench
```

ma Windows **non mostra sempre l’output dei programmi Linux compilati**, quindi sembra che non succeda nulla.

---

# 🧠 Regola importante per la tua tesi

Usa sempre:

```
WSL / Ubuntu terminal
```

per:

* Verilog
* Verilator
* simulazione CPU

Non PowerShell.

---

✅ Quindi il flusso corretto sarà sempre:

```bash
wsl
cd /mnt/c/Users/ACER/Desktop/universita/tesi
verilator -Wall --cc *.v --exe
cd obj_dir
make -f Vtestbench.mk
./Vtestbench
```

---

💡 Se vuoi, nel prossimo messaggio possiamo fare **il prossimo passo vero della tua tesi**, cioè:

**far eseguire alla CPU una vera istruzione RISC-V** (tipo `ADD x3,x1,x2`) e vedere i registri cambiare nella simulazione. Questo è il primo vero milestone del progetto.
