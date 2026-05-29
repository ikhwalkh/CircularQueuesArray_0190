//membuat file program queue C++
#include <iostream>
using namespace std;

// menambahkan class Queues dan deklarasi atribut
class Queues
{
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_array[max];

//menambahkan constructor default pada class Queues
public:
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    //membuat fungsi insert() pada queue
    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //menambahkan validasi queue overflow
        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow";
            return;
        }

        //menambahkan logika circular queue pada insert
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            // jika rear berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }

        queue_array[REAR] = num;
    }

    //membuat fungsi remove() pada queue
    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow";
            return;
        }

        cout << "\nThe element deleted from the queue is: "
             << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display()
    {
        int FRONT_Position = FRONT;
        int REAR_Position = REAR;

        // cek apakah antrian kosong
        if (FRONT_Position == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // jika FRONT < REAR, iterasi dari FRONT hingga REAR
        if (FRONT_Position <= REAR_Position)
        {
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            cout << endl;
        }
        else
        {
            // jika FRONT > REAR, iterasi dari FRONT hingga akhir array
            while (FRONT_Position <= max - 1)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            FRONT_Position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            cout << endl;
        }
    }
};

//menambahkan object queue di main()
int main()
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement Insert operasi\n" << endl;
            cout << "2. Implement Delete Operasi\n" << endl;
            cout << "3. Display values\n" << endl;
            cout << "4. Exit " << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }

            case '2':
            {
                q.remove();
                break;
            }

            case '3':
            {
                q.display();
                break;
            }

            case '4':
            {
                return 0;
            }

            default:
            {
                cout << "Invalid option!!!" << endl;
                break;
            }
            }
        }

        catch (exception &ex)
        {
            cout << "Check for the values entered." << endl;
        }
    }

    return 0;
}