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

var field = $('body');
function CreateList(list) {
    let ul = $('<ul>').appendTo(field);
    for(let prop in list) {

        let li = $('<li>', {
            text: list[prop]['text'],
            class: 'active'}).appendTo(ul);

        li.click(function (event){
            $(this).contents().slideToggle('fast');
            event.stopPropagation();
        });
        field = li;

        if (list[prop]['childs']) {
            CreateList(list[prop]['childs']);
        }
    }
}
CreateList(container);

$('li').each(function() {
    console.log(
        $(this).contents()[0],
        $(this).find('li').length
    );
});