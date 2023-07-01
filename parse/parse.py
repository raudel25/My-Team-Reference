import json

f = open('parse/in.txt', 'r')
file = f.read()
f.close()

file = file.split('\n')

name = file[0]
prefix = name.lower()
file = file[1:]

json_obj = {'prefix': prefix, 'body': file, 'description': ''}
json_obj = json.dumps(json_obj)

f = open('parse/out.json', 'w')
f.write(json_obj)
f.close()
