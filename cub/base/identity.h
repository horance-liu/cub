#ifndef F81351B27_9134_1399_D677_7562D007102E
#define F81351B27_9134_1399_D677_7562D007102E

namespace cub {

template <typename T>
struct identity {
  using type = T;
};

template <typename T>
using identity_t = typename identity<T>::type;

} // namespace cub

#endif
