#include <string>

using namespace std;
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
    private:
        string pid;
        string user;
        string cmd;
        string cpu;
        string mem;
        string time;

    public:
        Process(string pid) {
            this->pid = pid;
            this->user = ProcessParser::getProcUser(pid);
            this->mem = ProcessParser::getVmSize(pid);
            this->cmd = ProcessParser::getCmd(pid);
            this->time = ProcessParser::getProcUpTime(pid);
            this->cpu  = ProcessParser::getCpuPercent(pid);
        }
        void setPid(string pid);
        string getPid() const;
        string getUser() const;
        string getCmd() const;
        string getCpu() const;
        string getMem() const;
        string getUpTime() const;
        string getProcess();
};

void Process::setPid(string pid) {
    this->pid = pid;
}

string Process::getPid() const {
    return this->pid;
}

string Process::getProcess() {
    this->mem = ProcessParser::getVmSize(this->pid);
    this->time = ProcessParser::getProcUpTime(this->pid);
    this->cpu = ProcessParser::getCpuPercent(this->pid);

    return (this->pid + "   "
            + this->user
            + "   "
            + this->mem.substr(0,5)
            + "     "
            + this->cpu.substr(0,5)
            + "     "
            + this->time.substr(0,5)
            + "    "
            + this->cmd.substr(0,30)
            + "...");
}
