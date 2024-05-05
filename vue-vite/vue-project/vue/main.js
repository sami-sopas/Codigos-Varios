//Componente padre
const app = Vue.createApp({
    data() {
        return {
            textSize: 1,
            course: 
                { id: 1, name: 'Curso de Vue.js', price: '$30' },
            
        }
    },
    methods: {
        crecer(size){
            this.textSize += size;
        }
    }
});

app.component('button-counter', {
    data() {
        return {
            count: 0
        }
    },
    template: `<button @click="count++"> Haz hecho click: {{ count }} veces </button>`
});

//Componente hijo
app.component('detail-course', {

    props: ['course'],

    template: `
        <h1>{{ course.name }}</h1>
        <p>Precio: {{ course.price }}</p>
        <slot></slot>
        <button @click="$emit('crecer-texto', 1)">Incrementar tamaño</button>
    `,
})