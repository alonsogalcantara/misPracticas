from pip import main


DATA = [
    {
        'name': 'Facundo',
        'age': 72,
        'organization': 'Platzi',
        'position': 'Technical Coach',
        'language': 'python',
    },
    {
        'name': 'Luisana',
        'age': 33,
        'organization': 'Globant',
        'position': 'UX Designer',
        'language': 'javascript',
    },
    {
        'name': 'Héctor',
        'age': 19,
        'organization': 'Platzi',
        'position': 'Associate',
        'language': 'ruby',
    },
    {
        'name': 'Gabriel',
        'age': 20,
        'organization': 'Platzi',
        'position': 'Associate',
        'language': 'javascript',
    },
    {
        'name': 'Isabella',
        'age': 30,
        'organization': 'Platzi',
        'position': 'QA Manager',
        'language': 'java',
    },
    {
        'name': 'Karo',
        'age': 23,
        'organization': 'Everis',
        'position': 'Backend Developer',
        'language': 'python',
    },
    {
        'name': 'Ariel',
        'age': 32,
        'organization': 'Rappi',
        'position': 'Support',
        'language': '',
    },
    {
        'name': 'Juan',
        'age': 17,
        'organization': '',
        'position': 'Student',
        'language': 'go',
    },
    {
        'name': 'Pablo',
        'age': 32,
        'organization': 'Master',
        'position': 'Human Resources Manager',
        'language': 'python',
    },
    {
        'name': 'Lorena',
        'age': 56,
        'organization': 'Python Organization',
        'position': 'Language Maker',
        'language': 'python',
    },
]


def pythonDevsAndWorkers():
    '''Reto 3
    > Crear una lista all_python_devs y all_Platzi_workers usando una combinacion de filter y map
    '''
    all_python_devs_and_Platzi_workers = list(
        filter(lambda x: x['language'] == 'python' and x['organization'] == 'Platzi',  DATA))
    all_python_devs_and_Platzi_workers = list(
        map(lambda x: x['name'], all_python_devs_and_Platzi_workers))
    return all_python_devs_and_Platzi_workers


def oldAndAdults():
    '''Reto 3
    > Crear lal ista old_people y adults con list comprehension'''
    old_people = [x['name'] for x in DATA if x['age'] > 50]
    adults = [(x['name'], x['age'])
              for x in DATA if x['age'] > 18]

    return old_people, adults


if __name__ == '__main__':
    print(pythonDevsAndWorkers())
    print(oldAndAdults())
