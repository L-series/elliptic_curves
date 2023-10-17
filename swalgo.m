

h = 20




with open("b2_ekies_script.txt", "a") as output_file:
    for b4 in range(-2*h**4, 2*h**4+1):
        b6_dict = {}
        for x in range(-h**2, h**2+1):
            for y in range(0, 2*h**3+1):
                b6 = y**2-4*x**3-b2*x**2-2*b4*x

                # Update the counter for the b6 value
                if b6 in b6_dict:
                    b6_dict[b6] += 1
                else:
                    b6_dict[b6] = 1

    # Write the value of b4 and the b6_dict to the output file on the same line
    output_file.write(f"b4: {b4}, b6_dict: {b6_dict}\n")
