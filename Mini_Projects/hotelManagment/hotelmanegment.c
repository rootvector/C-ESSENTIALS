#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXPERSONS 5
#define MAXROOMS 10

struct Customer {
    char name[100];
    int ID;
};

struct Room {
    int roomNo, durationHr, guest;
    double payment, balance;
    struct Customer cust[MAXPERSONS];
    int isBooked; // 0 for empty, 1 for booked
};

// Function to register a room
void regCustomer(struct Room* room) {
    double cost = 0;
    
    printf("\n--- Register Room %d ---\n", room->roomNo);
    printf("[] Duration (Hours): ");
    scanf("%d", &room->durationHr);

    printf("[] Guest in Room [max %d]: ", MAXPERSONS);
    scanf("%d", &room->guest);

    if (room->guest > MAXPERSONS || room->guest <= 0) {
        printf("Invalid number of Guests!\n");
        return;
    }

    for (int i = 0; i < room->guest; i++) {
        printf("  [+] Name for Guest %d: ", i + 1);
        getchar(); // Clear buffer
        fgets(room->cust[i].name, sizeof(room->cust[i].name), stdin);
        room->cust[i].name[strcspn(room->cust[i].name, "\n")] = 0;
        printf("  [+] Id for Guest %d: ", i  + 1);
        scanf("%d", &room->cust[i].ID);
    }

    cost = room->guest * (100.0 * room->durationHr);
    printf("[] Total Cost: %.2lf. Enter Payment: ", cost);
    scanf("%lf", &room->payment);

    room->balance = cost - room->payment;
    room->isBooked = 1; 
    printf("Registration Complete! Balance: %.2lf\n", room->balance);
}

// Function to display all booked rooms
void showBookedRooms(struct Room rooms[], int size) {
    int found = 0;
    printf("\n================ Current Bookings ================\n");
    for (int i = 0; i < size; i++) {
        if (rooms[i].isBooked) {
            found = 1;
            printf("Room No: %d | Guestss: %d | Balance: %.2f\n", 
                    rooms[i].roomNo, rooms[i].guest, rooms[i].balance);
            for(int j = 0; j < rooms[i].guest; j++) {
                printf("  - %s\n", rooms[i].cust[j].name);
                printf("  -%d\n", rooms[i].cust[j].ID);
            }
            printf("------------------------------------------------\n");
        }
    }
    if (!found) printf("No rooms currently booked.\n");
}

int main() {
    struct Room hotel[MAXROOMS];
    int choice, roomIdx;

    // Initialize room numbers
    for (int i = 0; i < MAXROOMS; i++) {
        hotel[i].roomNo = 101 + i;
        hotel[i].isBooked = 0;
    }

    while (1) {
        printf("\n--- HOTEL MANAGEMENT SYSTEM ---\n");
        printf("1] Book Room\n2] Show Booked Rooms\n3] Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select Room Index (0 to %d): ", MAXROOMS - 1);
                scanf("%d", &roomIdx);
                if (roomIdx >= 0 && roomIdx < MAXROOMS) {
                    if (hotel[roomIdx].isBooked) {
                        printf("Room already booked!\n");
                    } else {
                        regCustomer(&hotel[roomIdx]);
                    }
                } else {
                    printf("Invalid room index.\n");
                }
                break;
            case 2:
                showBookedRooms(hotel, MAXROOMS);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
