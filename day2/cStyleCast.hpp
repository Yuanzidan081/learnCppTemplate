template <typename srcT, typename dstT>
dstT cStyleCast(srcT val)
{
    return (dstT)(val);
}

template <typename dstT, typename srcT>
dstT cStyleCast2(srcT val)
{
    return (dstT)(val);
}
