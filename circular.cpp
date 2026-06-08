/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * Project ini merupakan project structur data
 * menggunakan structur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section Cara penggunaan 
 * Berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - nama : ikhwal islami pasya
 * - nim  : 20250140190
 * - kelas : D
 * 
 * @brief
 * @version 0.1
 * @date 2026-06-08
 * 
 * @copyright ikhwal.islami.ft25@mail.umy.ac.id (c) 2026 
 * 
 */

//membuat file program queue C++
#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 * 
 * 
 */


// menambahkan class Queues dan deklarasi atribut
class Queues
{
private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_array[max];

//menambahkan constructor default pada class Queues
public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }
    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */

    //membuat fungsi insert() pada queue
    void insert()
    {
        int num;////< variable num untuk menyimpan nilai
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

    /**
     * @brief method untuk menghapus data dalam antrian
     * data dihapuskan dari dalam variable queue_array
     */

    //membuat fungsi remove() pada queue
    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow";
            return;
        }
        //menambahkan output elemen yang dihapus
        cout << "\nThe element deleted from the queue is: "
             << queue_array[FRONT] << "\n";
      
        //Menambahkan logika circular queue pada remove
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
    /**
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilkan yang berada dalam variable queue_array
     */

    //Membuat fungsi display() untuk queue
    void display()
    {
        int FRONT_Position = FRONT; /////< variable front_position untuk menandakan posisi element pertama pada variable front
        int REAR_Position = REAR;///////< variable rear_position untuk menandakan posisi element terakhir pada variable rear

        // cek apakah antrian kosong
        if (FRONT_Position == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        //Menambahkan logika display circular queue
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
            // jika FRONT_position > REAR_position, literasi dari FRONT hingga akhir array
            while (FRONT_Position <= max - 1)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            FRONT_Position = 0;

            // literasi dari awal array hingga REAR
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array[FRONT_Position] << " ";
                FRONT_Position++;
            }

            cout << endl;
        }
    }
};
/**
 * @brief method utama untuk menjalankan program
 */

//menambahkan object queue di main()
int main()
{
    Queues q;////< objek untuk menggunakan member yang ada pada class queues
    char ch; /////< variable ch untuk menyimpan pilihan pada menu yang diberikan

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

            switch (ch) //menambahkan switch untuk operasi queue
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

            default: //Finalisasi program circular queue dengan insert delete display
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