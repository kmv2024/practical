#include <iostream>
#include <vector>
using namespace std;

struct Block {
    int size, allocated;
};

struct Process {
    int size, allocatedBlockIndex;
};

void firstFit(vector<Block>& blocks, vector<Process>& processes) {
    for (auto& process : processes) {
        process.allocatedBlockIndex = -1;
        for (size_t i = 0; i < blocks.size(); i++) {
            if (!blocks[i].allocated && blocks[i].size >= process.size) {
                blocks[i].allocated = 1;
                process.allocatedBlockIndex = i;
                break;
            }
        }
    }
}

void bestFit(vector<Block>& blocks, vector<Process>& processes) {
    for (auto& process : processes) {
        process.allocatedBlockIndex = -1;
        int bestIndex = -1;
        for (size_t i = 0; i < blocks.size(); i++) {
            if (!blocks[i].allocated && blocks[i].size >= process.size) {
                if (bestIndex == -1 || blocks[i].size < blocks[bestIndex].size) {
                    bestIndex = i;
                }
            }
        }
        if (bestIndex != -1) {
            blocks[bestIndex].allocated = 1;
            process.allocatedBlockIndex = bestIndex;
        }
    }
}

void worstFit(vector<Block>& blocks, vector<Process>& processes) {
    for (auto& process : processes) {
        process.allocatedBlockIndex = -1;
        int worstIndex = -1;
        for (size_t i = 0; i < blocks.size(); i++) {
            if (!blocks[i].allocated && blocks[i].size >= process.size) {
                if (worstIndex == -1 || blocks[i].size > blocks[worstIndex].size) {
                    worstIndex = i;
                }
            }
        }
        if (worstIndex != -1) {
            blocks[worstIndex].allocated = 1;
            process.allocatedBlockIndex = worstIndex;
        }
    }
}

void displayAllocation(const vector<Process>& processes) {
    for (size_t i = 0; i < processes.size(); i++) {
        if (processes[i].allocatedBlockIndex != -1)
            cout << "Process " << i + 1 << " allocated to Block " 
                 << processes[i].allocatedBlockIndex + 1 << endl;
        else
            cout << "Process " << i + 1 << " not allocated" << endl;
    }
}

int main() {
    int numBlocks, numProcesses;
    
    cout << "Enter number of blocks: ";
    cin >> numBlocks;
    
    vector<Block> blocks(numBlocks);
    
    cout << "Enter sizes of blocks:\n";
    for (int i = 0; i < numBlocks; i++) {
        cin >> blocks[i].size;
        blocks[i].allocated = 0;
    }

    cout << "Enter number of processes: ";
    cin >> numProcesses;

    vector<Process> processes(numProcesses);
    
    cout << "Enter sizes of processes:\n";
    for (int i = 0; i < numProcesses; i++) {
        cin >> processes[i].size;
        processes[i].allocatedBlockIndex = -1;
    }

    cout << "\nFirst Fit Allocation:\n";
    firstFit(blocks, processes);
    displayAllocation(processes);
    
    for (auto& block : blocks) block.allocated = 0;
    for (auto& process : processes) process.allocatedBlockIndex = -1;

    cout << "\nBest Fit Allocation:\n";
    bestFit(blocks, processes);
    displayAllocation(processes);
    
    for (auto& block : blocks) block.allocated = 0;
    for (auto& process : processes) process.allocatedBlockIndex = -1;

    cout << "\nWorst Fit Allocation:\n";
    worstFit(blocks, processes);
    displayAllocation(processes);

    return 0;
}