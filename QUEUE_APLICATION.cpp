
// Application       ||   ,Queue का काम
// 1.Simulation,       ||   असली दुनिया की लाइनों का मॉडल बनाना।
// 2.OS Scheduling,    ||    CPU को Tasks सही क्रम में देना।
// 3.Printer Spooling, ||    प्रिंट जॉब्स को मैनेज करना।
// 4.Buffer,           ||   डेटा स्पीड के अंतर को संभालना।
// 5.Mail Queue,       ||   ईमेल्स को डिलीवरी के लिए लाइन में रखना।




#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// --- 1. Simulation (Bank Customer) ---
struct Customer { string name; int serviceTime; };

// --- 2. OS Scheduling (Process) ---
struct Process { int id; string taskName; };

// --- 3. Printer Spooling (Document) ---
struct Doc { string fileName; int pages; };

// --- 5. Mail Queue (Email) ---
struct Email { string receiver; string subject; };

int main() {
    // Sabhi Queues ko Initialize karna
    queue<Customer> bankQueue;
    queue<Process> cpuReadyQueue;
    queue<Doc> printerSpooler;
    queue<char> keyboardBuffer; // --- 4. Buffer ---
    queue<Email> mailServer;

    // --- DATA INPUT (Enqueuing) ---
    
    // Simulation: Bank me log aaye
    bankQueue.push({"Rahul", 5});
    
    // OS Scheduling: CPU ko kaam mila
    cpuReadyQueue.push({101, "Antivirus Scan"});
    
    // Printer Spooling: Print command di gayi
    printerSpooler.push({"Resume.pdf", 2});
    
    // Buffer: User ne keyboard par 'A' press kiya
    keyboardBuffer.push('A');
    
    // Mail Queue: Email bheja gaya
    mailServer.push({"boss@office.com", "Monthly Report"});

    // --- EXECUTION (Processing all Applications) ---

    cout << "===== SMART MANAGER SYSTEM (Queue Applications) =====\n" << endl;

    // 1. Simulation logic
    cout << "[1. Simulation]: Serving " << bankQueue.front().name << " at Counter 1." << endl;
    bankQueue.pop();

    // 2. OS Scheduling logic
    cout << "[2. OS Scheduling]: CPU is now running Process ID: " << cpuReadyQueue.front().id << " (" << cpuReadyQueue.front().taskName << ")" << endl;
    cpuReadyQueue.pop();

    // 3. Printer Spooling logic
    cout << "[3. Printer Spooling]: Printing File: " << printerSpooler.front().fileName << " (" << printerSpooler.front().pages << " pages)" << endl;
    printerSpooler.pop();

    // 4. Buffer logic
    cout << "[4. Keyboard Buffer]: Character '" << keyboardBuffer.front() << "' sent to screen from buffer." << endl;
    keyboardBuffer.pop();

    // 5. Mail Queue logic
    cout << "[5. Mail Queue]: Email successfully sent to: " << mailServer.front().receiver << endl;
    mailServer.pop();

    cout << "\n=====================================================" << endl;
    cout << "Sari Queues process ho chuki hain (FIFO Logic Complete)." << endl;

    return 0;
}