Il problema è semplice: **stai eseguendo il comando nel posto sbagliato**.
**Verilator** è installato nel tuo **ambiente Linux (WSL)**, ma tu stai usando **PowerShell di Windows**, dove il comando `verilator` non esiste.

Infatti prima avevi eseguito il progetto qui:

```
acerlinux@LAPTOP-D5L4HT83:/mnt/c/Users/ACER/Desktop/universita/tesi$
```

quello è **Linux (WSL)**.

---

# ✅ Come eseguire correttamente il progetto

## 1️⃣ Apri il terminale Linux (WSL)

Non usare PowerShell.

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

# 2️⃣ Vai nella cartella del progetto

```bash
cd /mnt/c/Users/ACER/Desktop/universita/tesi
```

---

# 3️⃣ Controlla che i file ci siano

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

# 4️⃣ Compila con Verilator

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
