def solve_expression(expression):
    try:

        result = eval(expression)
    except Exception as e:
        print(f"Error evaluating expression '{expression}': {e}")
        result = None
    return result


input_file = "Input.txt"
output_file = "Output.txt"

# Read input file
with open(input_file, "r") as file:
    expressions = file.readlines()

# Solve expressions
solved_expressions = []
for expression in expressions:
    expression = expression.strip()
    result = solve_expression(expression)
    if result is not None:
        solved_expression = f"{expression} = {result}\n"
        solved_expressions.append(solved_expression)


with open(output_file, "w") as file:
    file.writelines(solved_expressions)

print("Arithmetic expressions solved and answers written to output file.")
