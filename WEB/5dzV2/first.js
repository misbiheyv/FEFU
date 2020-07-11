var container = [
    {
        text: 'Животныe',
        childs: [
            {
                text: 'Млекопитающие',
                childs: [
                    {
                        text: 'Коровы'
                    },
                    {
                        text: 'Ослы'
                    },
                    {
                        text: 'Собаки'
                    },
                    {
                        text: 'Тигры'
                    }
                ]
            },
            {
                text: 'Другие',
                childs: [
                    {
                        text:'Змеи'
                    },
                    {
                        text: 'Птицы'
                    },
                    {
                        text: 'Ящерицы'
                    },
                ]
            }
        ]
    },
    {
        text: 'Рыбы',
        childs: [
            {
                text: 'Аквариумные',
                childs: [
                    {
                        text: 'Гуппи'
                    },
                    {
                        text: 'Скалярии'
                    }
                ]
            },
            {
                text: 'Морские',
                childs: [
                    {
                        text: 'Морская форель'
                    }
                ]
            }
        ]
    }
];

let field = document.getElementsByTagName('body')[0];
let i = 0;

function CreateList(list){
    // creating new table partition
    let menu = document.createElement('ul');

    list.forEach(primary_menu => {
        // creating new table element
        let next_level_menu = document.createElement('li');

        if(!primary_menu['childs']){
            next_level_menu.appendChild(document.createTextNode(primary_menu.text));
            menu.appendChild(next_level_menu);
            return menu;
        }

        next_level_menu.appendChild(document.createTextNode(primary_menu.text));
        next_level_menu.appendChild(CreateList(primary_menu.childs));
        menu.appendChild(next_level_menu);
    });
    return menu;
}

let list = CreateList(container);
field.appendChild(list);

var list_nodes = document.childNodes;

function ChildsHierarchy(nodes) {
    if(nodes != null){
        for(child_node of nodes){
            if(child_node instanceof HTMLElement){
                console.log(child_node);
                ChildsHierarchy(child_node.firstChild);
            }
        }
    }
}


window.onload = function() {
    ChildsHierarchy(list_nodes);
}