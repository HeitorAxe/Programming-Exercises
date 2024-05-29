import os
import yaml
from collections import defaultdict

# Configuration
ROOT_DIR = os.path.dirname(os.path.abspath(__file__))  # Change this to the path of your root directory
README_FILE = 'README.md'
YAML_DIR = 'yaml_files'  # Directory to store YAML files

# Template for new problem YAML file
def create_problem_template(problem_name, source_name):
    return {
        'name': problem_name,
        'source': source_name,
        'category': 'NA',
        'tags': []
    }

# Function to read or create problem details in a YAML file
def read_or_create_problem_details(yaml_path, problem_name, source_name):
    if not os.path.exists(yaml_path):
        with open(yaml_path, 'w') as file:
            template = create_problem_template(problem_name, source_name)
            yaml.dump(template, file)
    with open(yaml_path, 'r') as file:
        return yaml.safe_load(file)

# Create YAML directory if it doesn't exist
yaml_path = os.path.join(ROOT_DIR, YAML_DIR)
os.makedirs(yaml_path, exist_ok=True)

# Data structure to hold problem details
problems = defaultdict(lambda: defaultdict(list))  # problems[source][category] = [(name, filepath, tags)]

# Function to scan through the root directory and collect problem details
for source_name in os.listdir(ROOT_DIR):
    if source_name not in ['current', 'blocked']:  # Skip 'current' and 'blocked' directories
        source_dir = os.path.join(ROOT_DIR, source_name)
        if os.path.isdir(source_dir):
            for problem_file in os.listdir(source_dir):
                if problem_file.endswith('.cpp'):
                    problem_name = problem_file[:-4]  # Remove the '.cpp' extension
                    problem_path = os.path.join(source_dir, problem_file)
                    yaml_name = f"{problem_name}.yaml"
                    yaml_path = os.path.join(ROOT_DIR, YAML_DIR, yaml_name)
                    details = read_or_create_problem_details(yaml_path, problem_name, source_name)
                    relative_path = os.path.relpath(problem_path, ROOT_DIR)
                    problems[source_name][details['category']].append((details['name'], relative_path, details['tags']))

# Function to create the table for problems
def create_problem_table(problems_dict):
    table = "| Name | Source | Category | Tags |\n"
    table += "| --- | --- | --- | --- |\n"
    for source, categories in problems_dict.items():
        for category, problem_list in categories.items():
            for name, filepath, tags in problem_list:
                tag_string = ", ".join(tags)
                table += f"| [{name}]({filepath}) | {source} | {category} | {tag_string} |\n"
    return table

# Generate the README content
readme_content = "# Programming Problems\n\n"
readme_content += "## Problems Organized by Source and Category\n\n"
readme_content += create_problem_table(problems)

# Write the README content to a file
with open(os.path.join(ROOT_DIR, README_FILE), 'w') as readme_file:
    readme_file.write(readme_content)

print("README.md file has been created successfully.")
