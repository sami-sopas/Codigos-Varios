<template lang="">
    <h1> Vista del post {{ $route.params.post }} del usuario {{ $route.params.user }}</h1>
</template>

<script>
export default {
    mounted() {
        console.log(this.$route.params); // { user: "johndoe", post: "1"}
    }
}
</script>

<style lang="">
    
</style>