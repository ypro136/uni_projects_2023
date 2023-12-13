#include <iostream> 
#include "Music_player.hpp"
using namespace std;

// DLL
template<typename T>
class DLL {
private:
	struct Node {
		T value;
		Node* prev;
		Node* next;

		Node(T value) {
			this->value = value;
			prev = nullptr;
			next = nullptr;
		}


	};

	Node* head = nullptr;
	Node* tail = nullptr;
	Node* current = nullptr;

	int count{ 0 };

	Node* NodeAt(int index) {
		Node* temp = head;
		while (index != 0) {
			temp = temp->next;
			index--;
		}

		return temp;
	}

public:
	void Insert(T value)		//Default Insert At The End.
	{
		Node* newNode = new Node(value);
		count++;

		if (IsEmpty()) {
			head = tail = current = newNode;
			return;
		}

		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	void InsertAt(T value, int index)
	{
		if (index >= count)			// insert at the end.
		{
			Insert(value);
			return;
		}

		Node* newNode = new Node(value);
		count++;

		if (index == 0)				// insert at the start.
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;

			return;
		}

		Node* temp = NodeAt(index);

		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		newNode->next = temp;
	}

	T Remove()
	{
		if (IsEmpty())
			throw new exception();

		T value = tail->value;

		if (count == 1) {
			delete tail;

			head = tail = nullptr;

			count = 0;
			return value;
		}

		Node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;

		count--;
		return value;
	}

	T RemoveAt(int index)
	{
		if (IsEmpty())
			throw new exception();

		if (index >= count)			// Remove from the end.
			return Remove();

		T value;
		count--;

		if (index == 0)				// Remove from the start.
		{
			Node* temp = head;
			head = head->next;
			head->prev = nullptr;
			value = temp->value;

			delete temp;

			return value;
		}

		Node* temp = NodeAt(index);
		value = temp->value;

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		delete temp;

		return value;
	}

	T MoveNext()
	{
		return current->next ? (current = current->next)->value : (current = head)->value;
	}

	T MovePrev()
	{
		return current->prev ? (current = current->prev)->value : (current = tail)->value;
	}

	bool IsEmpty() { return !head; }

	bool Search(T value) {
		Node* temp = head;
		while (temp)
		{
			if (temp->value == value)
				return true;

			temp = temp->next;
		}

		return false;
	}

	int Count() { return count; }

	void print() {
		Node* temp = head;
		while (temp) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
};

class MusicPlayer {
public:
	struct Music {
		string songName;
		Music(string name) {
			songName = name;
		}
	};

private:
	DLL<Music*>* musicList = new DLL<Music*>();

	Music* currentSong = nullptr;

	bool isPlaying = false;
public:

	void AddMusic(Music* song)
	{
		if (musicList->Search(song))
			return;

		if (!currentSong)
			currentSong = song;

		musicList->Insert(song);
	}

	void Play() {
		isPlaying = !isPlaying;
		if (isPlaying)
			cout << currentSong->songName << " is Playing Right Now..." << endl;
		else
			cout << currentSong->songName << " is Paused Right Now..." << endl;
	}

	void PlayNextMusic() {
		isPlaying = false;
		currentSong = musicList->MoveNext();
		Play();
	}

	void PlayPrevMusic() {
		isPlaying = false;
		currentSong = musicList->MovePrev();
		Play();
	}
};
