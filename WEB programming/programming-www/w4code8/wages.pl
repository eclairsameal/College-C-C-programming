# wages.pl - An example program to illustrate some of the 
#            features of Perl
#  Input: A file of lines of employee data, where each line has
#         name:age:department code:salary
# Output: 1. The names of all employees whose names end with "son"
#         2. Percentage of employees under 40 years old
#         3. Average salary of employees under 40 years old
#         4. An alphabetical list of employees who are under 40
#            years old and who have salaries more than $40,000

# Open the data file and display a header for employees 
#  whose names end in 'son'

open(EMPLOYEES, "employees.txt") || die "Can't open employees $!";
print "Names that end in 'son'\n\n";

# Loop to read and process the employee data

while (<EMPLOYEES>) {

# Increment the number of employees and chop off the newline

    $total_employees++;
    chomp;

# Split the input line into its four parts

    ($name, $age, $dept, $salary) = split(/:/);

# If the name ends in 'son', print the name

    if ($name =~ /son$/) {
        print "$name \n";
    }

# If the employee is under 40, count him or her and add his or her
#  salary to the sum of such salaries

    if ($age < 40) {
        $under_40++;
        $salary_sum += $salary;

# If the salary was over 40,000, add the person and his or her 
#  salary to the hash of such people

        if ($salary > 40000) {
            $sublist{$name} = $salary;
        }
    }
}

# If there was at least one employee, continue

if ($total_employees > 0) {

# If there was at least one under 40, continue 
  
    if ($under_40 > 0) {

# Compute and display the % of employees under 40 and their
#  average salaries

        $percent = 100 * $under_40 / $total_employees;
        print "\nPercent of employees under 40 is: $percent \n";
        $avg = $salary_sum / $under_40;
        print "Average salary of employees under 40 is: $avg \n";

# If there was at least one under 40 who earned a salary > 40,000,
#  continue

        if (keys(%sublist)) {

# Sort and display the names of the employees under 40 with 
#  with salaries > 40,000

            print "Sorted list of employees under 40",
                  " with salaries > \$40,000 \n";
            @sorted_names = sort (keys(%sublist));
            print "\nName \t\t Salary\n";
            foreach $name (@sorted_names) {
                print "$name \t \$$sublist{$name} \n";
            }
        }
        else {
            print "There were no employees under 40 who earned";
            print "over $40,000 \n";
        }  #** of if (keys(%sublist))
    }
    else {
        print "There were no employees under 40 \n";
    }  #** of if ($under_40 > 0)
}
else {
    print "There were no employees\n";
}  #** of if ($total_employees > 0)

