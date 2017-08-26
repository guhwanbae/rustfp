/**
 * Contains forwarding declaration for Result.
 * Only for use by Result.
 * Rust Result: https://doc.rust-lang.org/std/result/enum.Result.html
 * @author Chen Weiguang
 * @version 0.1.0
 */

#pragma once

#include "traits.h"

namespace rustfp {

    // forwarding section

    namespace details {
        template <class T>
        class OkImpl;

        template <class E>
        class ErrImpl;
    }

    template <class T, class E>
    class Result;

    template <class T>
    auto Ok(T &&value) -> details::OkImpl<special_decay_t<T>>;

    template <class E>
    auto Err(E &&error) -> details::ErrImpl<special_decay_t<E>>;
}
