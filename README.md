# Mini-Kurs-MoveSemantik
 Mini-Kurs zur Move-Semantik in C++ inkl. YouTube-Videos

Dieses Tutorial ist Teil des Mini-Kurses „Move-Semantik in C++“ im YouTube-Kanal "The Fearless Engineer".  

## Teaser

Seit der Einführung von C++11 können wir mit Hilfe der Move-Semantik die Performance unseres Codes noch einmal deutlich erhöhen. Zwei der wesentlichen Vorteile sind dabei das Einsparen von unnötigen Kopien bei der Übergabe von Daten sowie das automatische Deallokieren von Heap-Speicher. 

In diesem Tutorial erfährst du, wie du die Konzepte der Move-Semantik in deine eigenen Klassen einbaust und ein konsistentes und sicheres Speichermanagement entwickelst. In insgesamt 17 Code-Beispielen geht es im ersten Teil um ein paar wichtige Grundlagen und danach im zweiten Teil um die eigentliche Move-Semantik und deren Anwendung. Im dritten Teil wird in einem Beispielprogramm die Performance der Move-Semantik mit der klassischen Copy-Semantik verglichen.

Zu den Code-Beispielen findest du Erklärvideos und ein ausführliches Skript auf www.thefearlessengineer.com. 


----

## Inhalt

Im folgenden sind alle Code-Beispiele des Mini-Kurses aufgelistet. Der Grundlagenteil besteht aus insgesamt vier Abschnitten zu vorbereitenden Themen, die für ein gutes Verständnis der Move-Semantik wichtig sind. Im Hauptteil werden dann die wesentlichen Konzepte der Move-Semantik behandelt und in einem ausführlichen Abschlussprojekt mit der klassischen Copy-Semantik verglichen. 

Die Kennung vor jedem Code-Beispiel (z.B. *MS-1-1-L1*) dient dazu, beim Kompilieren das richtige Listing auszuwählen (siehe Abschnitt *Build-Anweisungen*). 

### Grundlagen
* **Stack und Heap**
		* MS1-1-L1 : Wachstumsrichtung des Stack-Speichers ermitteln
		* MS1-1-L2 : Speicherbedarf von Funktionen auf dem Stack ermitteln
		* MS1-1-L3 : Speicherbedarf von Heap-Variablen auf  Heap und Stack untersuchen 
		* MS1-1-L4 : Laufzeitvergleich beim Zugriff auf Stack- und Heap-Speicher 
* **Parameterübergabe**
		* MS1-2-L5 : Ermittlung der Speicherbelegung von Funktionen für *CallByValue*
		* MS1-2-L6 : Ermittlung der Speicherbelegung von Funktionen für *CallByReference*
		* MS1-2-L7 : Analyse der Auswirkungen von `const` auf das Verhalten von *CallByReference* 
* **Copy-Semantik**
		* MS1-3-L9 : Implementierung der *Rule of Three* in einer eigenen Klasse
		* MS1-3-L11 : Durchführung einer *Shallow Copy* von Instanzen einer eigenen Klasse
		* MS1-3-L12 : Umwandlung der Copy-Semantik von *Shallow Copy* zu *Deep Copy*
* **Lvalues und Rvalues**
		* MS1-3-L13 : Unterschiede zwischen *Lvalues* und *Rvalues* erkennen
		* MS1-3-L14 : *Lvalue-Referenzen* als Alias-Identifier verwenden
		* MS1-3-L15 : *Lvalue-Referenzen* als Parameter und Rückgabetyp in Funktionen verwenden

### Move-Semantik
* **Rvalue-Referenzen**
		* MS2-1-L16 : *Rvalue-Referenzen* als Alias-Identifier und als Parameter in Funktionen verwenden
* **Die „Rule of Five“**
		* MS2-2-L18 : Überschreiben von Move-Konstruktor und Move-Zuweisungsoperator
		* MS2-2-L19 : Sicheres Verschieben von Objekten mit Hilfe der Move-Semantik
* **Performance-Vergleich „Copy“ vs. „Move“** 
		* MS3-1 : Performance-Vergleich zwischen Copy- und Move-Semantik

---

## Vorbereitungen

Im folgenden ist eine Liste der erforderlichen Entwicklungswerkzeuge aufgeführt, die zum Ausführen des Codes erforderlich sind. 

* **cmake** >= 2.8 
	* Alle Betriebssysteme:  [klicken Sie hier für Installationsanweisungen](https://cmake.org/install/) 
* **make** >= 4.1 (Linux, Mac), 3.81 (Windows) 
	* Linux: *make* ist auf den meisten Linux-Distributionen standardmäßig installiert. 
	* Mac:  [Xcode-Befehlszeilen-Tools installieren (enthalten make)](https://developer.apple.com/xcode/features/) 
	* Windows: [Klicken Sie hier für die Installationsanleitung](http://gnuwin32.sourceforge.net/packages/make.htm) 
* **gcc/g++** >= 5.4 
	* Linux: gcc / g++ ist standardmäßig auf den meisten Linux-Distributionen installiert. 
	* Mac: [Xcode-Befehlszeilen-Tools installieren (enthalten make)](https://developer.apple.com/xcode/features/) 
	* Windows: empfohlen wird die Installation von [MinGW](http://www.mingw.org/) 
	
-----

## Build-Anweisungen 

Die Code-Listings lassen sich sehr einfach individuell kompilieren. Um ein bestimmtes Listing auszuwählen, wird die im folgenden aufgeführte Schrittfolge empfohlen. 

1.  Dieses Repository klonen. 
2.  Ein Build-Verzeichnis auf der obersten Ebene erstellen: `mkdir build && cd build` 
3.  Kompilieren:  `cmake .. -DLISTING_ID=MSx-y-Lz && make` (für x, y und z siehe Abschnitt "Inhalt")
4.  Ausführen: ./MSx-y-Lz