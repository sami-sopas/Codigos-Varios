import { computed } from 'vue';
import { useRoute, useRouter } from 'vue-router';

export default function usePagination() {
    const limits = [5, 10, 15, 20];

        const route = useRoute(); //Para poder acceder this.route desde el metodo setup
        const router = useRouter(); //Para poder acceder this.router desde el metodo setup

        //Propiedades computadas
        const page = computed(() => {
            //Busca en la url, la palabra limit, si no hay nada, retorna 5
            return route.query.limit ?? 5;
        })

        //Metodos
        const changeLimit = (limit) => {
            router.push({ query: { limit: limit } });
        }

        return {
            limits,
            page,
            changeLimit
        }
}