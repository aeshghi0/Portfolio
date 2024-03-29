
import subprocess
import time

# Function that runs the tracerout command line for 20 second before checking the output
def traceroute_runner(host):
    try:
        # Running the command line: traceroute -w 2 [host]
        res = subprocess.run(['traceroute', '-w', '2', host], capture_output=True, text=True, timeout=20)

        # Checks if the host was unreachable
        if len(res.stdout) == 0:
            return "Traceroute: failed"

        return res.stdout
    
    # Time out Error output
    except subprocess.TimeoutExpired:
        return "Traceroute: failed"
    
    # To-Be-Asked...
    ##except subprocess.CalledProcessError:
    ##    return "Traceroute: failed"
    
# Function to count the hops between the source and the destination
# hosts based on the number of lines on the traceroute output
def count_hops(traceout_output):
    return len(traceout_output.splitlines())

def main():

    # Prompt the user for a host input
    host = input("Enter a server name: ")

    # Run the commandline
    traceroute_output = traceroute_runner(host)

    # Check for error in traceroute output
    if "Traceroute: failed" in traceroute_output:
        print(traceroute_output)
    
    else:
        # Get the number of hops to the destination and prints for the user
        hops  = count_hops(traceroute_output)
        print(f"{hops} hops to: {host}")


if __name__ == "__main__":
    main()