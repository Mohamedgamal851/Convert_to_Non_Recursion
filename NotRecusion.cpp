
#include <iostream>
#include <stack>

using namespace std;

struct Call {
    int n;      // Parameter
    int a, b;   // Local variables
    int cur_loc; // Location of next statement to be executed
};

int G(int n) {
    stack<Call> st;
    int result = 0;

    // Initial call setup
    Call initial_call;
    initial_call.n = n;
    initial_call.cur_loc = 0;
    st.push(initial_call);

    while (!st.empty()) {
        Call& call = st.top();

        if (call.cur_loc == 0) {
            if (call.n <= 1) {
                result = 1;
                st.pop(); // Pop stack since call finished
            } else {
                // Create child call for F(n-1)
                Call child_call;
                child_call.n = call.n - 1;
                child_call.cur_loc = 0;
                st.push(child_call);

                call.cur_loc = 1; // Move to location 1
            }
        } else if (call.cur_loc == 1) {
            // Compute a = n * F(n - 1) + 7 * F(n / 2)
            call.a = call.n * result ;  // Use the updated result
            // Create child call for F(n/2)
            Call child_call;
            child_call.n = call.n / 2;
            child_call.cur_loc = 0;
            st.push(child_call);

            call.cur_loc = 2; // Move to location 1
        } else if (call.cur_loc == 2) {

            call.a += 7 * result ;
            // Create child call for F(n-3-a%2)
            Call child_call;
            child_call.n = call.n - 3 - (call.a % 2);
            child_call.cur_loc = 0;
            st.push(child_call);

            call.cur_loc = 3; // Move to location 2
        }
        else if (call.cur_loc == 3) {
            // Compute b = F(n - 3 - a % 2)
            call.b = result ;  // Use the updated result for the previous call

            // Calculate result = a + b
            result = call.a + call.b;
            st.pop(); // Pop stack since call finished
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Result of G(" << n << "): " << G(n) << endl;
    return 0;
}
