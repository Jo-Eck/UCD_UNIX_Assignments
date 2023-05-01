#!/bin/bash

# This script generates a BSc transcript.
# It supports an optional command-line argument to determine whether an internship is included in stage 3 or not.
# The script prints a formatted table with the module code, title, credit, grade, and grade points for each stage.
# It calculates the total grade points for each stage and the overall total grade points.
# Usage: bsctranscript.sh <I|NI>
# I for internship in stage 3
# NI for no internship in stage 3
# Load data from the required files

source ./assignment4data/stage1.sh.inc
source ./assignment4data/stage2.sh.inc
source ./assignment4data/stage3.sh.inc
source ./assignment4data/stage4.sh.inc
source ./assignment4data/grades.sh.inc
source ./assignment4data/mincredits.sh.inc

# Check if help is requested or no arguments are provided

if [ $# -eq 0 ] || [ "$1" == "--help" ]; then
  echo "Correct usage: bsctranscript.sh <I|NI>"
  echo "I for internship in stage 3"
  echo "NI for no internship in stage 3"
  exit 1
fi

if [ $# -ne 1 ] || [[ ! "$1" =~ ^(I|NI)$ ]]; then
  echo "Invalid arguments."
  echo "Correct usage: bsctranscript.sh <I|NI>"
  exit 1
fi

get_random_grade() {
  # This function returns a random grade and its corresponding grade point

  local idx=$((RANDOM % ((${#grades[@]}-1) / 2) * 2))
  echo "${grades[$idx]}" "${grades[$idx + 1]}"
}

print_transcript() {
  # This function prints the transcript for a given stage
  # It takes two arguments: stage number and whether an internship is included or not
  # It prints a formatted table with the module code, title, credit, grade, and grade points for each stage
  # It calculates the total grade points for each stage and the overall total grade points

  local stage=$1
  local arg=$2
  local -n core_modules="stage${stage}core"
  local -n elective_modules="stage${stage}elective"
  local stage_cred=0
  local stage_grade_points=0
  


  echo ""
  echo " Stage: $stage"
  echo ""
  echo "  Module     Title                                                Cred Grade G.P"
  echo "+===============================================================================+"

  # Print core modules
  for ((i = 0; i < ${#core_modules[@]}; i += 3)); do
    local module_code="${core_modules[$i]}"
    local module_name="${core_modules[$i + 1]}"
    local credits="${core_modules[$i + 2]}"

    read -r grade grade_point <<< "$(get_random_grade)"
    printf '| %-10s %-50s %4d %5s %4d |\n' "$module_code" "$module_name" "$credits" "$grade" "$grade_point"

    # Update the stage total credits and grade points
    stage_cred=$((stage_cred + credits))
    stage_grade_points=$((stage_grade_points + grade_point))

  done


  echo "+-------------------------------------------------------------------------------+"

  # Print elective modules until the minimum credits for the stage are reached
  while [ $stage_cred -lt ${minc[$stage-1]} ]; do
  local idx=0

    # If stage 3 and internship is included, pick the internship module
    if [ $stage -eq 3 ] && [ "$2" == "I" ]; then
        idx=0
    else
        # Pick a random module from the pool
        local idx=$((1 + RANDOM % ((${#elective_modules[@]}/3)-1 )))
    fi  


    local module_code="${elective_modules[$idx*3]}"
    local module_name="${elective_modules[$idx*3+1]}"
    local credits="${elective_modules[$idx*3+2]}"


    read -r grade grade_point <<< "$(get_random_grade)"
    printf '| %-10s %-50s %4d %5s %4d |\n' "$module_code" "$module_name" "$credits" "$grade" "$grade_point"

    # Update the stage total credits and grade points
    stage_cred=$((stage_cred + ${elective_modules[$idx*3+2]}))
    stage_grade_points=$((stage_grade_points + grade_point))


    # Remove the picket module form the pool
    elective_modules=("${elective_modules[@]:0:$idx*3}" "${elective_modules[@]:$((idx*3+3))}")
  done
  
  echo "+===============================================================================+"
  printf "| %-72s %4d |\n" "Stage $stage total grade points:" "$stage_grade_points"
  printf "| %-69s %4d/%2d |\n" "Stage $stage total credits:" "$stage_cred" "${minc[$stage-1]}"
  echo "+===============================================================================+"
  total_grade_points=$((total_grade_points + stage_grade_points)) 
  total_credits=$((total_credits + stage_cred))

}

# Print the transcript for each stage
total_grade_points=0
total_credits=0
for stage in 1 2 3 4; do
  print_transcript $stage $1

done
echo ""
echo "#################################################################################"
printf "# %-72s %4d #\n" "Overall total grade points:" "$total_grade_points"
printf "# %-72s %4d #\n" "Overall total credits: " "$total_credits" 
echo "#################################################################################"