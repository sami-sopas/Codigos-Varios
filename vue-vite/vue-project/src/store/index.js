import { createStore } from 'vuex'
import moduleCounter from './modules/moduleCounter' //cuando se exporta solo una variable
import { moduleUser} from './modules/moduleUser'

// Tienda principal de VueX
export default createStore({
    modules: {
        user: moduleUser,
        counter: moduleCounter
    }

})