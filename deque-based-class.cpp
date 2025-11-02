#include <deque>
#include <string>
#include <random>


class RandomQueue {
    std::deque<std::string> participants;

public:
    std::string selectNext() {
        if (participants.empty()) {
            return "No participants available.";
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 1);

        int random_bit = dist(gen);
        if (random_bit == 0) {
            std::string participant = participants.front();
            participants.pop_front();
            return participant;
        }
        else {
            std::string participant = participants.back();
            participants.pop_back();
            return participant;
        }
    }
    void addParticipant(const std::string& name) {
        participants.push_back(name);
	}
	RandomQueue() { }
};
